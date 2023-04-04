/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:19:47 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:14:42 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_calculate_width_zdot(t_tp *tp, t_flags *flags, int n)
{
	if (flags->minus != -1 && flags->width >= 0 && flags->width > n)
		tp->space_r = flags->width - n;
	else if (flags->minus == -1 && flags->width >= 0 && flags->width > n)
	{
		if (flags->zero == -1)
			tp->space_l = flags->width - n;
		else
		{
			if (flags->dot == -1)
				tp->zero_l = flags->width - n;
			else
				tp->space_l = flags->width - n;
		}
	}
}

void	ft_calculate_width(t_tp *tp, t_flags *flags, char *str)
{
	char	t;
	int		n;

	t = flags->data_type;
	n = 0;
	if (t == 'd' || t == 'i' || t == 'u' || t == 'x' || t == 'X')
	{
		n = tp->decimal_z + ft_strlen(str) + tp->sign + tp->sign_space;
		if ((t == 'x' || t == 'X') && flags->pad == 1)
			n = n + 2;
	}
	else if (flags->data_type == 'c' && *str == 0)
		n = 1;
	else
		n = ft_strlen(str);
	ft_calculate_width_zdot(tp, flags, n);
}
