/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:14:41 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:14:42 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

static int	check_flag(char *arg, int n)
{
	int	i;

	i = 1;
	if (arg[0] != '-')
		return (0);
	while (arg[i])
	{
		if (arg[i] != n)
			return (0);
		i++;
	}
	return (1);
}

int	run_echo(char **input)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (input[i] && ft_strequ(input[i], "-n") &&\
	check_flag(input[i], 'n') && (n = 1))
		i++;
	while (input[i])
	{
		ft_putstr(input[i]);
		if (input[++i])
			write(1, " ", 1);
	}
	if (n == 0)
		write(1, "\n", 1);
	return (1);
}