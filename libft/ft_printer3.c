/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:19:47 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:14:42 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_process_f_s_pad(t_tp *tp, t_flags *flags, char **str, int n)
{
	char	*s;
	char	t;

	t = flags->data_type;
	if (t == 's' && flags->dot == 1 && n > flags->decimals)
	{
		s = malloc(sizeof(char) * ft_strlen(*str));
		ft_strlcpy(s, *str, flags->decimals + 1);
		free (*str);
		*str = s;
	}
	if (flags->pad == 1 && t == 'x')
		tp->low_hex = 1;
	else if (flags->pad == 1 && t == 'X')
		tp->cap_hex = 1;
}

void	ft_process_flags(t_tp *tp, t_flags *flags, char **str)
{
	char	t;
	int		n;

	t = flags->data_type;
	n = ft_strlen(*str);
	if (t == 'd' || t == 'i' || t == 'u' || t == 'x' || t == 'X')
	{
		if (flags->number >= 0 && flags->space == 1)
			tp->sign_space = 1;
		else if (flags->number >= 0 && flags->plus == 1)
			tp->sign = 1;
		if (flags->dot == 1 && flags->decimals > 0)
		{
			if (((n - (flags->number < 0)) < flags->decimals))
				tp->decimal_z = flags->decimals - (n - (flags->number < 0));
		}
		else if (flags->dot == 1 && flags->decimals == 0 && flags->number == 0)
			*str[0] = 0;
	}
	ft_process_f_s_pad(tp, flags, str, n);
	ft_calculate_width(tp, flags, *str);
}

int	ft_write_xchars(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write (1, &c, 1);
		i++;
	}
	return (n);
}

int	ft_write_char(t_tp *tp, char c)
{
	tp->cap_hex = 0;
	write (1, &c, 1);
	free (tp);
	return (1);
}

int	ft_write_string(t_tp *tp, char *str, char t)
{
	int	n;

	n = ft_write_xchars (' ', tp->space_l);
	if ((t == 'd' || t == 'i' || t == 'u' || t == 'x' || t == 'X') && \
			*str == '-')
	{
		n += write (1, "-", 1);
		str++;
	}
	n += write (1, " ", tp->sign_space);
	n += write (1, "+", tp->sign);
	if (tp->cap_hex)
		n += write (1, "0X", 2);
	if (tp->low_hex)
		n += write (1, "0x", 2);
	n += ft_write_xchars ('0', tp->zero_l);
	n += ft_write_xchars ('0', tp->decimal_z);
	if (t == 'c' && *str == 0)
		n += write (1, "\0", 1);
	else
		n += write(1, str, ft_strlen(str));
	n += ft_write_xchars(' ', tp->space_r);
	free(tp);
	return (n);
}
