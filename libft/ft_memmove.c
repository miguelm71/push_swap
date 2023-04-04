/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:44:33 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:11:13 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	int	i;
	int	s;

	s = size;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		i = 0;
		while (i < s)
		{
			*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
			i++;
		}
	}
	else
	{
		i = s - 1;
		while (i >= 0)
		{
			*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
			i--;
		}
	}
	return (dst);
}
