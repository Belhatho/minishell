/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:32 by belhatho          #+#    #+#             */
/*   Updated: 2019/05/21 02:11:04 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*s;
	int			i;
	int			j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		s[i++] = s1[j];
	j = -1;
	while (s2[++j])
		s[i++] = s2[j];
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin2(char *s1, char *s2, int tofree)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (!(new))
		return (NULL);
	free(s1);
	s1 = NULL;
	if (tofree && s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (new);
}

char	*ft_strchjoin(const char *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!c)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	*(new_str + i + 1) = '\0';
	return (new_str);
}

char	*ft_strchjoinf(char *s1, char c)
{
	char	*new;

	new = ft_strchjoin(s1, c);
	if (!(new))
		return (NULL);
	free(s1);
	s1 = NULL;
	return (new);
}
