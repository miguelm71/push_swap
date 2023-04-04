/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:50:44 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:11:13 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_is_sep(char c, char s);

int	ft_get_words(const char *strg, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (strg[i] != '\0')
	{
		if (!ft_is_sep (strg[i], sep))
			if (!(ft_is_sep(strg[i], sep)) && (ft_is_sep(strg[i + 1], sep)))
				words++;
		i++;
	}
	return (words);
}

int	ft_is_sep(char c, char s)
{
	if (c == s || c == '\0')
		return (1);
	else
		return (0);
}

char	**ft_del(char **array, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free (array[i]);
		i++;
	}
	free (array);
	return (NULL);
}

char	**ft_dowork(char const *s, char c, char **array, int words)
{
	int		i;
	size_t	len;

	i = 0;
	while (i < words)
	{
		if (!ft_is_sep(*s, c))
		{
			len = 0;
			while (!ft_is_sep(s[len], c))
				len++;
			array[i++] = ft_substr(s, 0, len);
			if (array[i - 1] == NULL)
				return (ft_del(array, i - 1));
			s += (len + 1);
		}
		else
			s++;
	}
	array[words] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;

	words = ft_get_words(s, c);
	array = malloc(sizeof(char *) * (words +1));
	if (!array)
		return (NULL);
	return (ft_dowork(s, c, array, words));
}
