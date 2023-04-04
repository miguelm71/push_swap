/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:52:35 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:14:42 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_tp	*ft_init_to_print(void)
{
	t_tp	*tp;

	tp = (t_tp *)malloc (sizeof (t_tp));
	if (tp == NULL)
		return (NULL);
	tp->zero_l = 0;
	tp->space_l = 0;
	tp->space_r = 0;
	tp->decimal_z = 0;
	tp->sign = 0;
	tp->sign_space = 0;
	tp->cap_hex = 0;
	tp->low_hex = 0;
	return (tp);
}

int	ft_print_param(t_flags *flags, va_list *param_ptr)
{
	int		r;

	r = -1;
	if (flags->data_type == 'c')
		r = ft_print_char(flags, param_ptr);
	else if (flags->data_type == 's')
		r = ft_print_string(flags, param_ptr);
	else if (flags->data_type == 'p')
		r = ft_print_pointer(flags, param_ptr);
	else if (flags->data_type == 'd')
		r = ft_print_decimal(flags, param_ptr);
	else if (flags->data_type == 'i')
		r = ft_print_decimal(flags, param_ptr);
	else if (flags->data_type == 'u')
		r = ft_print_unsigned(flags, param_ptr);
	else if (flags->data_type == 'x')
		r = ft_print_hex(flags, param_ptr, 1);
	else if (flags->data_type == 'X')
		r = ft_print_hex(flags, param_ptr, 0);
	else if (flags->data_type == '%')
		r = ft_print_percentage(flags);
	return (r);
}

int	ft_print_char(t_flags *flags, va_list *param_ptr)
{
	int		c;
	t_tp	*tp;
	char	*str;
	int		n;

	tp = ft_init_to_print();
	if (tp != NULL)
	{
		str = malloc (sizeof(char) * 2);
		if (str == NULL)
			return (-1);
		str [1] = '\0';
		c = va_arg(*param_ptr, int);
		str[0] = c;
		ft_process_flags(tp, flags, &str);
		n = ft_write_string(tp, str, flags->data_type);
		free (str);
		return (n);
	}
	return (0);
}

int	ft_print_string(t_flags *flags, va_list *param_ptr)
{
	char	*str;
	char	*s;
	t_tp	*tp;
	int		n;

	tp = ft_init_to_print();
	if (tp != NULL)
	{
		str = NULL;
		s = va_arg(*param_ptr, char *);
		if (s != NULL)
			str = ft_strdup(s);
		if (str == NULL)
			str = ft_strdup("(null)");
		ft_process_flags(tp, flags, &str);
		n = ft_write_string(tp, str, flags->data_type);
		free(str);
		return (n);
	}
	return (0);
}

int	ft_print_pointer(t_flags *flags, va_list *param_ptr)
{
	unsigned long	p;
	char			*str;
	t_tp			*tp;
	int				n;

	tp = ft_init_to_print();
	if (tp != NULL)
	{
		p = (long long int)(va_arg(*param_ptr, void *));
		str = ft_p2string(p);
		if (str == NULL)
			return (-1);
		ft_process_flags(tp, flags, &str);
		n = ft_write_string(tp, str, flags->data_type);
		free (str);
		return (n);
	}
	return (0);
}
