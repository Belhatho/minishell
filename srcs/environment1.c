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