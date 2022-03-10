/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 04:50:10 by belhatho          #+#    #+#             */
/*   Updated: 2022/02/24 04:50:12 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

char	*do_path(char *name, char *d_name)
{
	char	*tmp;

	if (!d_name || !name)
		return (NULL);
	if (!ft_strendswith(name, "/"))
	{
		if (d_name[0] == '/')
			return (ft_strjoin(name, d_name));
		else
		{
			tmp = ft_strjoin2(ft_strchjoin(name, '/'), d_name, 0);
			return (tmp);
		}
	}
	else
	{
		if (d_name[0] == '/')
			return (ft_strjoin(name, d_name + 1));
		else
			return (ft_strjoin(name, d_name));
	}
}

char            *get_var(char *name, t_env m_env)
{
   	int		i;
	char	*tmp;
	t_env	env;

	env = m_env;
	i = -1;
	if (!env.vars || !name)
		return (NULL);
	while (env.vars[++i])
	{
		tmp = ft_strjoin(name, "=");
		// printf("LO: %s\n",tmp);
		if (is_first_word(env.vars[i], tmp))
		{
			ft_strdel(&tmp);
			return (ft_strchr(env.vars[i], '=') + 1);
		}
		ft_strdel(&tmp);
	}
	return (NULL);
}

int	find_var_index(char *var, t_env m_env)
{
	int		i;
	char	*tmp;

	i = -1;
	while (m_env.vars[++i])
	{
		tmp = ft_strchjoin(var, '=');
		if (ft_strstartswith(m_env.vars[i], tmp))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (i);
}


void	set_env_var(char *key, char *value, t_env m_env)
{
	int		pos;
	char	*tmp;
	int		len;

	pos = find_var_index(key, m_env);
	tmp = ft_strjoin("=", value);
	if (m_env.vars[pos])
	{
		free(m_env.vars[pos]);
		if (value)
			m_env.vars[pos] = ft_strjoin(key, tmp);
		else
			m_env.vars[pos] = ft_strjoin(key, "=");
	}
	else
	{
		len = ft_strlen2(m_env.vars);
		m_env.vars = realloc_env(m_env, len + 1);
		// if (value)
			m_env.vars[len] = ft_strjoin(key, tmp);
		// else
		// 	m_env.vars[len] = ft_strjoin(key, "=");
		printf("SET: %s= %s\n",key, get_var(key, m_env));
	}
	free(tmp);
}