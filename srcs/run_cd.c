/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:14:36 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:14:37 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		has_two_args(char **args)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*tmp;

	if (args[1])
	{
		if (args[2])
		{
			ft_putendl("cd: too many arguments");
			return (1);
		}
		cwd = getcwd(buff, 4096);
		if (!(tmp = ft_strreplace(cwd, args[0], args[1])))
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(args[0]);
			free(tmp);
			return (1);
		}
		change_dir(tmp, 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int				run_cd(char **input, t_env *m_env)
{
	char	*home;

	home = get_var("HOME", m_env);
	if (!input[1])
	{
		ft_chdir(home, 0, m_env);
		return (1);
	}
	if (has_two_args(input))
		return (1);
	else
	{
		if (ft_strequ(input[1], "--"))
		{
			ft_chdir(home, 0, m_env);
			return (1);
		}
		else if (input[1][0] == '-' && !input[0][2])
		{
			ft_chdir(get_var("OLDPWD", m_env), 1, env);
			return (1);
		}
		ft_chdir(input[1], 0, m_env);
	}
	return (1);
}
