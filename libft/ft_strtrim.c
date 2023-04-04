/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:58:25 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:11:13 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_char_present(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	stt;
	size_t	end;
	char	*r;

	stt = 0;
	while (s1[stt] && ft_char_present(set, s1[stt]))
		stt++;
	end = ft_strlen(s1);
	while (end > stt && ft_char_present(set, s1[end - 1]))
		end--;
	r = (char *)malloc (sizeof(char) * (end - stt + 1));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (stt < end)
		r[i++] = s1 [stt++];
	r[i] = '\0';
	return (r);
}
