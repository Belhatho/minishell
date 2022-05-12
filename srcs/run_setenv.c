/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:14:54 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:14:55 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	set_env_var(char *key, char *value)
{
	int		pos;
	char	*tmp;

	pos = find_var_index(key);
	tmp = ft_strjoin("=", value);
	if (m_env[pos])
	{
		free(m_env[pos]);
		m_env[pos] = ft_strjoin(key, tmp);

	}
	else
	{
		m_env = realloc_env(pos + 1);
		m_env[pos] = ft_strjoin(key, tmp);
	}
	free(tmp);
}

int     run_setenv(char **input)
{
    int     len;

    len = ft_strlen2(input);
    if (len == 1)
        print_env(*m_env);
    else if (len == 2)
        set_env_var(input[1], "");
    else if (len == 3)
        set_env_var(input[1], input[2]);
    else
        ft_putstr("setenv: Too many arguments.\n");
    return (1);
}
