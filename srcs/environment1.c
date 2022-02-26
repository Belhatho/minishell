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