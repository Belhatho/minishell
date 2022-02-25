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

# include "../inc/minishell.h"

int	print_env(char **m_envvars)// t_env m_env)
{
	int	i;

	i = -1;
	if (!m_envvars || !m_envvars[0])
		return (0);
	while (m_envvars && m_envvars[++i])
		ft_putendl(m_envvars[i]);
	return (1);
}

t_env	init_environment(int ac, char **av, char **env)
{
	int i;
	t_env	m_env;
	
	(void)ac;
	(void)av;
	
	i = -1;
	m_env.vars = (char**)ft_memalloc(ft_strlen2(env) + 1);
	while (env[++i])
	{
		m_env.vars[i] = ft_strdup(env[i]);
				// ft_putendl(m_env.vars[i]);
		if (!m_env.vars[i])
			free_exit(m_env);
	}
	m_env.vars[i] = NULL;
	/**/
	// i = -1;
	// while (m_env.vars[++i])
	// 	ft_put3str("--\t",m_env.vars[i], "\n");
	return (m_env);
}

 
char	**alloc_env(t_env m_env, int size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = -1;
	while (m_env.vars[++i] && i < size)
	{
		new[i] = ft_strdup(m_env.vars[i]);
		free(m_env.vars[i]);
	}
	free(m_env.vars);
	return (new);
}
