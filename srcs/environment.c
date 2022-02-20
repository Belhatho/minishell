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
	m_env.vars[i] = NULL;
	/**/
	return (m_env);
}
 /*
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
*/

char	*do_path(char *name, char *d_name)
{
	char	*path;
	char	*tmp;

	if ((name[0] == '/' && name[1] == '\0') ||
					name[ft_strlen(name) - 1] == '/' || d_name[0] == '/')
		path = ft_strjoin(name, d_name);
	else
	{
		tmp = ft_strjoin(name, "/");
		path = ft_strjoin(tmp, d_name);
		ft_strdel(&tmp);
	}
	return (path);
}

void	print_env(t_env m_env)
{
	char **var;
	int	i;

	i = 0;
	var = m_env.vars;


	while (var && var[i])
	{
		ft_put2str(var[i], "\n");
		i++;
	}
	
}


int		is_first_word(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char            *get_var(char *name, t_env m_env)
{
   	int		i;
	char	*tmp;
	t_env	env;

	env = m_env;
	i = -1;
	if (!env.vars)
		return (NULL);
	while (env.vars[++i])
	{
		tmp = ft_strjoin(name, "=");
		if (is_first_word(env.vars[i], tmp))
		{
			ft_strdel(&tmp);
			return (ft_strchr(env.vars[i], '=') + 1);
		}
		ft_strdel(&tmp);
	}
	return (NULL);
}