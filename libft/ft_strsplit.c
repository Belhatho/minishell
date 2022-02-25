/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:14:01 by belhatho          #+#    #+#             */
/*   Updated: 2019/05/21 19:50:34 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int		get_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int		ft_countwords(char const *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
		(ft_countwords(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if (!(str2[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			str2[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}

// static int	check_null(char const *s, char ***new_s, char c)
// {
// 	if (s == NULL)
// 		return (0);
// 	(*new_s) = (char **)malloc((ft_nbr_words(s, c) + 1) * sizeof(char *));
// 	if (!(**new_s))
// 		return (0);
// 	return (1);
// }



// char	**ft_strsplit(char const *s, char c)
// {
// 	int		i[3];
// 	char	**new_s;

// 	i[0] = 0;
// 	i[2] = 0;
// 	if (!check_null(s, &new_s, c))
// 		return (NULL);
// 	while (s[i[2]])
// 	{
// 		while (s[i[2]] == c && s[i[2]])
// 			i[2]++;
// 		if (s[i[2]])
// 		{
// 			i[1] = 0;
// 			new_s[i[0]] = (char *)malloc(ft_word_size(s, c, i[2]) + 1);
// 			if (!(new_s[i[0]]))
// 				return (NULL);
// 			while (s[i[2]] != c && s[i[2]])
// 				new_s[i[0]][i[1]++] = s[i[2]++];
// 			new_s[i[0]++][i[1]] = '\0';
// 		}
// 	}
// 	new_s[i[0]] = 0;
// 	return (new_s);
// }
