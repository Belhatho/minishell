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

void	unset_var(char *input)
{
	int pos;
	int	i;
	int	var_count;

	pos = find_var_index(input);
	if (m_env[pos])
	{
		free(m_env[pos]);
		m_env[pos] = NULL;
		i = pos;
		var_count = pos + 1;
		while (m_env[i + 1])
		{
			m_env[i] = ft_strdup(m_env[i + 1]);
			free(m_env[i + 1]);
			i++;
			var_count++;
		}
		m_env = realloc_env(var_count - 1);
	}
}



int     run_unsetenv(char **input)
{
	int     i;

	i = 0;
	if (!input[1])
		ft_putendl("unsetenv: Too few arguments.");
	else
	{
		while (input[++i])
			unset_var(input[i]);
	}
	return (1);
}
