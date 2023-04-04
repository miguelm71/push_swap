/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:37:18 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:14:42 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_parse_flags(char **str, t_flags *flags)
{
	int	n;
	int	m;

	n = 0;
	if (**str == '+')
		n = ft_set_plus_flag(flags);
	else if (**str == '-')
		n = ft_set_minus_flag(flags);
	else if (**str == ' ')
		n = ft_set_space_flag(flags);
	else if (**str == '.')
		n = ft_set_dot_flag(flags);
	else if (**str == '#')
		n = ft_set_pad_flag(flags);
	else if (**str == '0' && flags->zero == -1)
		n = ft_set_zero_flag(flags);
	else
	{
		m = ft_get_num(str);
		n = ft_set_flag_number(m, flags);
	}
	return (n);
}

int	ft_get_num(char **str)
{
	int	m;

	m = 0;
	while (ft_isdigit(**str))
	{
		m = (m * 10) + (**str - 48);
		if (ft_isdigit(*(*str + 1)))
			(*str)++;
		else
			return (m);
	}
	if (m > 0)
		(*str)--;
	return (m);
}

int	ft_set_flag_number(int n, t_flags *flags)
{
	if (flags->dot == -1)
	{
		if (flags->width == -1)
			flags->width = n;
		else
			return (-1);
	}
	else
	{
		if (flags->decimals == 0)
			flags->decimals = n;
		else
			return (-1);
	}
	return (0);
}

int	ft_set_minus_flag(t_flags *flags)
{
	if (flags->minus == -1)
	{
		flags->minus = 1;
		if (flags->zero != -1)
			flags->zero = -1;
		return (0);
	}
	return (0);
}
