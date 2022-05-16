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

#include "minishell.h"

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

void	check_quote(char *input)
{
	int	start;
	int	end;
	int	len;

	end = 0;
	start = 0;
	len = ft_strlen(input);
	if (input[0] == '"')
		start = 1;
	if (input[len - 1] == '"')
		end = 1;
	if (end && start)
		ft_putnstr(input + 1, len - 2);
	else if (end)
		ft_putnstr(input, len - 1);
	else if (start)
		ft_putstr(input + 1);
	else
		ft_putstr(input);
}

int	run_echo(char **input)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (input[++i] && ft_strequ(input[i], "-n") && \
	check_flag(input[i], 'n'))
		n = 1;
	while (input[i])
	{
		check_quote(input[i]);
		if (input[++i])
			write(1, " ", 1);
	}
	if (!n)
		write(1, "\n", 1);
	return (1);
}
