/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:06:02 by belhatho          #+#    #+#             */
/*   Updated: 2021/11/12 01:06:10 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char ***to)
{
	int		i;

	i = -1;
	while (to && (*to) && (*to)[++i])
		free((*to)[i]);
	free((*to));
	(*to) = NULL;
}
