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
		ft_put4str("my_sh: ", "command not found: ", cmd, "\n");
		exit(-1);
	}
	wait(&pid);
	return (1);
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
		ret = check_one_cmd(cmd);
		if (ret == 0)
			ft_put4str("my_sh: ", "command not found: ", cmd[0], "\n");
		ft_free(&cmd);
		if (ret == -1)
			break ;
	}
	ft_free(commandss);
	return (ret);
}
