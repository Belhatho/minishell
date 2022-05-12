/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:52:52 by belhatho          #+#    #+#             */
/*   Updated: 2022/05/12 03:53:10 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtin(char **cmd)
{
	if (ft_strequ(cmd[0], "exit"))
		return (-1);
	if (ft_strequ(cmd[0], "env"))
		return (print_env());
	if (ft_strequ(cmd[0], "setenv"))
		return (run_setenv(cmd));
	if (ft_strequ(cmd[0], "unsetenv"))
		return (run_unsetenv(cmd));
	if (ft_strequ(cmd[0], "cd"))
		return (run_cd(cmd));
	if (ft_strequ(cmd[0], "echo"))
		return (run_echo(cmd + 1));
	return (0);
}

int	check_exec(char *path, struct stat st, char **input)
{
	if (st.st_mode & S_IFREG)
	{
		if (st.st_mode & S_IEXEC)
			return (run(path, input));
		else
			ft_put3str("my_sh: permision denied: ", input[0], "\n");
		return (1);
	}
	if (st.st_mode & S_IFDIR)
	{
		ft_chdir(input[0], 0);
		return (1);
	}
	return (0);
}

static int	is_bin(char **input)
{
	struct stat	st;
	char		**path;
	char		*exc;
	int			i;

	i = 0;
	path = ft_strsplit(get_var("PATH"), ':');
	while (path && path[i])
	{
		if (is_first_word(path[i], input[0]))
			exc = ft_strdup(input[0]);
		else
			exc = do_path(path[i], input[0]);
		if (lstat(exc, &st) == -1)
			ft_strdel(&exc);
		else if (check_exec(exc, st, input))
		{
			ft_strdel(&exc);
			ft_free(&path);
			return (1);
		}
		i++;
	}
	ft_free(&path);
	return (0);
}

int	check_one_cmd(char **input)
{
	int			isbuiltin;
	struct stat	st;

	isbuiltin = is_builtin(input);
	if (isbuiltin == -1)
		return (-1);
	if (isbuiltin == 1 || is_bin(input))
		return (1);
	if (lstat(input[0], &st) != -1)
		return (check_exec(input[0], st, input));
	return (0);
}
