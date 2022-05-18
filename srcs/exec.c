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

int	is_bin(char ***in)
{
	struct stat	st;
	char		**path;
	char		*exc;
	char		**input;
	int			i;


	i = 0;
	input = *in;
	path = ft_strsplit(get_var("PATH"), ':');
	while (path && path[i])
	{
		if (is_first_word(path[i], input[0]))
			exc = ft_strdup(input[0]);
		else
			exc = do_path(path[i], input[0]);
		if (lstat(exc, &st) == -1)
			ft_strdel(&exc);
		else 
		{
			int	ret;
			ret = check_exec(exc, st, in);
			ft_strdel(&exc);
			ft_free(&path);
			if (ret == -2)
				free_exit();
			if (ret == 1)
				return (1);
		}
		i++;
	}
	ft_free(&path);
	return (0);
}

int	is_builtin(char ***cmds)
{
	char **cmd;

	cmd = *cmds;
	if (ft_strequ(cmd[0], "exit"))
	{
		ft_free(cmds);
		return (-1);
	}
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
