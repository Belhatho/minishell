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

void	print_env(t_env m_env)
{
	int	i;

	i = 0;

	if (!m_env.vars || m_env.vars[0] == '\0')
		return ;
	while (m_env.vars[i])
	{
		ft_put2str(m_env.vars[i], "\n");
		i++;
	}
	
}

t_env	init_environment(int ac, char **av, char **env)
{
	int i;
	t_env	m_env;
	
	(void)ac;
	(void)av;
	
	i = 0;
	m_env.vars = (char**)ft_memalloc(ft_strlen2(env) + 1);
	while (env[i])
	{
		m_env.vars[i] = ft_strdup(env[i]);
		if (!m_env.vars[i])
			free_exit(m_env);
		i++;
	}
	m_env.vars[i] = 0;
	/**/
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
