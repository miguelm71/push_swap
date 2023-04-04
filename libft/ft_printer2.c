/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:03:35 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:14:42 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_decimal(t_flags *flags, va_list *param_ptr)
{
	long	p;
	char	*str;
	t_tp	*tp;
	int		n;

	tp = ft_init_to_print();
	p = (long int)(va_arg(*param_ptr, int));
	flags->number = p;
	str = ft_d2string(p, "0123456789");
	if (str == NULL)
		return (-1);
	ft_process_flags(tp, flags, &str);
	n = ft_write_string(tp, str, flags->data_type);
	free (str);
	return (n);
}

int	ft_print_unsigned(t_flags *flags, va_list *param_ptr)
{
	unsigned long	p;
	char			*str;
	t_tp			*tp;
	int				n;

	tp = ft_init_to_print();
	p = (long int)(va_arg(*param_ptr, unsigned int));
	flags->number = p;
	str = ft_d2string(p, "0123456789");
	if (str == NULL)
		return (-1);
	ft_process_flags(tp, flags, &str);
	n = ft_write_string(tp, str, flags->data_type);
	free (str);
	return (n);
}

int	ft_print_hex(t_flags *flags, va_list *param_ptr, int low)
{
	unsigned int	p;
	char			*str;
	t_tp			*tp;
	int				n;

	tp = ft_init_to_print();
	if (tp != NULL)
	{
		p = (va_arg(*param_ptr, int));
		flags->number = p;
		if (p == 0)
			flags->pad = -1;
		if (!low)
			str = ft_d2string(p, "0123456789ABCDEF");
		else
			str = ft_d2string(p, "0123456789abcdef");
		if (str == NULL)
			return (-1);
		ft_process_flags(tp, flags, &str);
		n = ft_write_string(tp, str, flags->data_type);
		free (str);
		return (n);
	}
	return (0);
}

int	ft_print_percentage(t_flags *flags)
{
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
		str [0] = '%';
		ft_process_flags(tp, flags, &str);
		n = ft_write_string(tp, str, flags->data_type);
		free (str);
		return (n);
	}
	return (0);
}
