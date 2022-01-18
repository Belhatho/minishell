/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:01:39 by belhatho          #+#    #+#             */
/*   Updated: 2019/05/21 20:03:42 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	surdix(int *test)
{
	*test /= 10;
	return (*test);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	size;
	int	test;

	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb == -2147483648)
	{
		ft_putchar_fd(50, fd);
		nb = 147483648;
	}
	size = 1;
	test = nb;
	while (surdix(&test) != 0)
		size *= 10;
	while (size != 0)
	{
		test = nb / size;
		nb %= size;
		size /= 10;
		ft_putchar_fd(test + 48, fd);
	}
}
