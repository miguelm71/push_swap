/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:22:21 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:12:11 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	param_ptr;
	int		n;
	int		m;

	n = 0;
	va_start(param_ptr, str);
	while (*str)
	{
		if (ft_strncmp(str, "%", 1) == 0)
		{
			str++;
			m = ft_get_flags((char **)(&str), &param_ptr);
			if (m == -1)
				return (n);
			n = n + m;
		}
		else
		{	
			ft_putchar_fd((char)(*str), 1);
			n++;
		}
		if (ft_strncmp(str, "", 1) != 0)
			str++;
	}
	return (n);
}
