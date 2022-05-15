/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:15:06 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:15:09 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_var(char *input)
{
	int	pos;
	int	i;
	int	var_count;

	pos = find_var_index(input);
	if (g_env[pos])
	{
		free(g_env[pos]);
		g_env[pos] = NULL;
		i = pos;
		var_count = pos + 1;
		while (g_env[i + 1])
		{
			g_env[i] = ft_strdup(g_env[i + 1]);
			free(g_env[i + 1]);
			i++;
			var_count++;
		}
		g_env[i] = 0;
		g_env = realloc_env(var_count - 1);
	}
}

int	run_unsetenv(char **input)
{
	int	i;

	i = 0;
	if (!input || !input[1])
		ft_putendl("unsetenv: Too few arguments.");
	else
	{
		while (input && input[++i])
			unset_var(input[i]);
	}
	return (1);
}
