/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:05:01 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:15:24 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_plen(unsigned long int n, unsigned int b_len)
{
	int	i;

	i = 1;
	while (n >= b_len)
	{
		n = n / b_len;
		i++;
	}
	return (i);
}

int	ft_dlen(long long int n, unsigned int b_len)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i ++;
	}
	while (n >= b_len)
	{
		n = n / b_len;
		i++;
	}
	return (i);
}

char	*ft_p2string(unsigned long p)
{
	int		i;
	char	*str;
	char	*g_base;

	g_base = "0123456789abcdef";
	i = ft_plen(p, 16) + 2;
	str = malloc (sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str [i] = '\0';
	str[0] = '0';
	str[1] = 'x';
	i--;
	while (p >= 16)
	{
		str[i] = g_base[p % 16];
		p = p / 16;
		i--;
	}
	str[i] = g_base[p];
	return (str);
}

char	*ft_d2string(long p, char *base)
{
	int		i;
	int		blen;
	char	*str;

	blen = ft_strlen (base);
	i = ft_dlen(p, blen);
	str = malloc (sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str [i] = '\0';
	i--;
	if (p < 0)
	{
		p = p * -1;
		str[0] = '-';
	}	
	while (p >= blen)
	{
		str[i] = base[p % blen];
		p = p / blen;
		i--;
	}
	str[i] = base[p];
	return (str);
}
