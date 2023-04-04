/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:58:48 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:11:13 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = NULL;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		ret = malloc (sizeof(char));
		if (ret == NULL)
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

char	*ft_substr_b(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	l;

	l = ft_strlen(s);
	if (start > l)
	{
		str = malloc (sizeof(char) * 1);
		str[0] = '\0';
	}
	str = malloc (sizeof(char) * (ft_strlen(s + start) + 1));
	if (!s || str == NULL)
		return (NULL);
	i = 0;
	while ((start < l) && (s[i] != '\0') && (i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
