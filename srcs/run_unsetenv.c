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

void	unset_var(char *input, t_env *m_env)
{
	int pos;
	int	i;
	int	var_count;

	pos = find_var_index(input, m_env);
	if (m_env->vars[pos])
	{
		free(m_env->vars[pos]);
		m_env->vars[pos] = NULL;
		i = pos;
		var_count = pos + 1;
		while (m_env->vars[i + 1])
		{
			m_env->vars[i] = ft_strdup(m_env->vars[i + 1]);
			free(m_env->vars[i + 1]);
			i++;
			var_count++;
		}
		m_env->vars = realloc_env(m_env, var_count - 1);
	}
}



int     run_unsetenv(char **input, t_env *m_env)
{
	int     len;
	int     i;

	i = 0;
	if (!input[1])
		ft_putendl("unsetenv: Too few arguments.");
	else
	{
		while (input[++i])
			unset_var(input[i], m_env);
	}
	return (1);
}
