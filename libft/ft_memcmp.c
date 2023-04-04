/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:43:31 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:11:13 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(str1 + i)) != (*(unsigned char *)(str2 + i)))
			return ((*(unsigned char *)(str1 + i)) - \
					(*(unsigned char *)(str2 + i)));
		i++;
	}
	return (0);
}
