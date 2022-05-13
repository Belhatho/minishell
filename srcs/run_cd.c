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

void	ft_chdir(char *path, int print)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		// ft_put2str("lop0\n","");
		if (print)
			ft_putendl(parse_home(path, 0));
		// ft_put2str("lop1\n","");
		set_env_var("OLDPWD", cwd);
		// ft_put2str("lop2\n","");

	}
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putendl(path);
	}
}

static int	has_two_args(char **args)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*tmp;

	if (args[2])
	{
		if (args[3])
		{
			ft_putendl("cd: too many arguments");
			return (1);
		}
		cwd = getcwd(buff, 4096);
		tmp = strreplace(cwd, args[1], args[2]);
		if (!tmp)
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(args[1]);
			free(tmp);
			return (1);
		}
		ft_chdir(tmp, 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int	run_cd(char **input)
{
	char	*home;

	home = get_var("HOME");
	if (!input[1])
	{
		ft_chdir(home, 0);
		return (1);
	}
	if (has_two_args(input))
		return (1);
	if (ft_strequ(input[1], "--"))
	{
		ft_chdir(home, 0);
		return (1);
	}
	else if (input[1][0] == '-' && !input[0][2])
	{
		ft_chdir(get_var("OLDPWD"), 1);
		return (1);
	}
	ft_chdir(input[1], 0);
	return (1);
}
