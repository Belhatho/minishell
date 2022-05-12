/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 02:06:17 by belhatho          #+#    #+#             */
/*   Updated: 2022/05/12 01:48:48 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strechr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s)
	{
		while (s[i] && i)
		{
			if (s[i] == (char)c)
				return ((char *)(s + i));
			i--;
		}
	}
	return ((char *)s);
}
