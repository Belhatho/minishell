/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:08:40 by belhatho          #+#    #+#             */
/*   Updated: 2021/11/12 01:08:46 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **ptr, size_t old, size_t len)
{
	void	*real;

	real = malloc(len);
	ft_memset(real, 0, len);
	if (real)
		ft_memcpy(real, *ptr, old);
	if (*ptr)
		free(*ptr);
	return (real);
}
