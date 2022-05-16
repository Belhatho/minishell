/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:22:04 by belhatho          #+#    #+#             */
/*   Updated: 2022/02/26 03:22:10 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isempty(char **str)
{
	int	i;
	int	ret;

	i = -1;
	ret = 1;
	while (str && (*str) && (*str)[++i])
	{
		if ((*str)[i] > 32 && (*str)[i] <= 126)
			ret = 0;
	}
	if (ret)
		free(*str);
	return (ret);
}

int	is_first_word(char *s1, char *s2)
{
	int	i;

	i = -1;
	if (!s1 || !s2)
		return (0);
	while (s2[++i] && s1[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
