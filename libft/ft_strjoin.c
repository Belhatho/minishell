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
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
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

static	void	ft_free_join(char **s1, char **s2, int tofree)
{
	if (tofree == 0)
		free(*s1);
	else if (tofree == 1)
		free(*s2);
	else if (tofree == 2)
	{
		free(*s1);
		free(*s2);
	}
}

char	*ft_strjoin2(char *s1, char *s2, int tofree)
{
	char		*frch;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	frch = (char *)malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(frch))
		return (NULL);
	while (s1[i] != '\0')
	{
		frch[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		frch[i] = s2[j];
		i++;
		j++;
	}
	frch[i] = '\0';
	ft_free_join(&s1, &s2, tofree);
	return (frch);
}
