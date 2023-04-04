/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:29:12 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:14:42 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_get_flags(char **str, va_list *param_ptr)
{
	int		result;
	t_flags	*flags;

	result = 0;
	flags = ft_init_flags();
	while ((ft_is_type(**str) || ft_is_flag(**str)) && !result && flags != NULL)
	{
		if (ft_is_flag(**str))
			result = ft_parse_flags(str, flags);
		else if (ft_is_type(**str))
		{
			result = ft_set_type_flag(**str, flags);
			if (!result)
			{
				result = ft_print_param(flags, param_ptr);
				ft_end_flags(flags);
				return (result);
			}
		}
		else
			result = 1;
		(*str)++;
	}
	ft_end_flags(flags);
	return (-1);
}
