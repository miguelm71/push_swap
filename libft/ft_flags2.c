/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:39:25 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:14:42 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_is_flag(char c)
{
	if (c == '+' || c == '-' || c == ' ' || c == '.' || c == '#'
		|| ft_isdigit(c))
		return (1);
	else
		return (0);
}

/**/
int	ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

t_flags	*ft_init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)malloc (sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->data_type = 0;
	flags->dot = -1;
	flags->minus = -1;
	flags->plus = -1;
	flags->pad = -1;
	flags->space = -1;
	flags->width = -1;
	flags->zero = -1;
	flags->decimals = 0;
	return (flags);
}

void	ft_end_flags(t_flags *flags)
{
	if (flags != NULL)
		free (flags);
}

int	ft_set_type_flag(char t, t_flags *flags)
{
	if (flags->data_type == 0)
	{
		flags->data_type = t;
		return (0);
	}
	return (-1);
}
