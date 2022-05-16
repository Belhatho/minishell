/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:58:38 by belhatho          #+#    #+#             */
/*   Updated: 2019/05/21 19:58:42 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	ft_put2str(char const *s, char const *s1)
{
	ft_putstr(s);
	ft_putstr(s1);
}

void	ft_put3str(char const *s, char const *s1, char const *s2)
{
	ft_put2str(s, s1);
	ft_putstr(s2);
}

void	ft_put4str(char const *s, char const *s1, char const *s2, \
		char const *s3)
{
	ft_put3str(s, s1, s2);
	ft_putstr(s3);
}

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = -1;
	if (n < 0)
		ft_putstr(str);
	else
	{
		while (str[++i] && i < n)
			ft_putchar(str[i]);
	}
}
