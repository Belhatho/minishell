/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:19:03 by belhatho          #+#    #+#             */
/*   Updated: 2022/05/16 13:36:50 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run(char *cmd, char **input)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, ft_child_signal);
	if (pid < 0)
	{
		ft_put3str("my_sh: ", "Fork failed to create a new process.", "\n");
		return (0);
	}
	if (pid == 0 && execve(cmd, input, g_env) == -1)
	{
		ft_put2str("my_sh: command not found: ", input[0]);
		return (-1);
	}
	wait(&pid);
	return (1);
}

int	check_exec(char *path, struct stat st, char ***in)
{
	char	**input;

	input = *in;
	if (st.st_mode & S_IFREG)
	{
		if (st.st_mode & S_IXUSR)
		{
			if (run(path, input) == -1)
			{
				ft_free(in);
				return (-2);
			}
		}
		else
			ft_put3str("my_sh: permision denied: ", input[0], "\n");
		ft_free(in);
		return (1);
	}
	if (st.st_mode & S_IFDIR && ft_strlen2(input) == 1)
	{
		ft_chdir(input[0], 0);
		ft_free(in);
		return (1);
	}
	return (0);
}

int	check_one_cmd(char ***input)
{
	int			isbuiltin;
	struct stat	st;
	int			ret;

	isbuiltin = is_builtin(input);
	if (isbuiltin == -1)
		return (-1);
	if (isbuiltin || is_bin(input))
		return (1);
	if (lstat((*input)[0], &st) != -1)
	{
		ret = check_exec((*input)[0], st, input);
		if (ret == -2)
			free_exit();
		return (ret);
	}
	return (0);
}

int	execution(char ***commandss)
{
	int		i;
	int		ret;
	char	**cmd;
	char	**commands;

	i = -1;
	ret = 1;
	commands = *commandss;
	while (commands && commands[++i])
	{
		cmd = ft_strsplits(commands[i]);
		ret = check_one_cmd(&cmd);
		if (ret == -1)
			break ;
		if (ret == 0)
			ft_put4str("my_sh: ", "command not found: ", cmd[0], "\n");
		ft_free(&cmd);
	}
	ft_free(commandss);
	return (ret);
}
