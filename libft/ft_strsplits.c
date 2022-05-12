/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 05:00:01 by belhatho          #+#    #+#             */
/*   Updated: 2022/02/25 05:00:08 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(char const *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (!(str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_countwordsall(char const *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!((str[i] == ' ' || str[i] == '\t')) && str[i] != '\0')
			count++;
		while (!((str[i] == ' ' || str[i] == '\t')) && str[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_strsplits(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	str2 = (char **)malloc(sizeof(*str2) * (ft_countwordsall(s) + 1));
	if (!s || !(str2))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwordsall(s))
	{
		k = 0;
		str2[i] = ft_strnew(get_word_len(&s[j]) + 1);
		if (!(str2[i]))
			str2[i] = NULL;
		while (s[j] == ' ' || s[j] == '\t')
			j++;
		while (!(s[j] == ' ' || s[j] == '\t') && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}
