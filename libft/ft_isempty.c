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

int	ft_isempty(char *str, int consider_space)
{
	int	i;
	int	min;
	int	max;

	i = -1;
	min = 32 + consider_space;
	max = 126;
	while (str[++i])
	{
		if (str[i] >= min && str[i] <= max)
			return (0);
	}
	return (1);
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
