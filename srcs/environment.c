/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:25:49 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:25:51 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	print_env()
{
	int	i;

	i = -1;
	if (!m_env || !m_env[0])
		return (0);
	while (m_env && m_env[++i])
		ft_putendl(m_env[i]);
	return (1);
}

void	init_environment(int ac, char **av, char **env)
{
	int i;

	(void)ac;
	(void)av;
	i = -1;
	m_env = (char**)ft_memalloc(sizeof(char*) * (ft_strlen2(env) + 1));
	while (env[++i])
	{
		m_env[i] = ft_strdup(env[i]);
		if (!m_env[i])
			free_exit();
	}
	m_env[i] = NULL;
	ft_putendl("\n\x1b[32;01m my_sh strating...\033[0m");
}

char	**realloc_env(int size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = -1;
	while (m_env && m_env[++i] && i < size)
	{
		new[i] = ft_strdup(m_env[i]);
		free(m_env[i]);
	}
	new[size] = NULL;
	free(m_env);
	m_env = NULL;
	return (new);
}
