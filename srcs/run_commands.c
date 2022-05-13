/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:19:03 by belhatho          #+#    #+#             */
/*   Updated: 2022/03/14 04:42:13 by belhatho         ###   ########.fr       */
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
	else if (pid == 0)
	{
		if (execve(cmd, input, g_env) == -1)
		{
			ft_put3str("my_sh: command not found: ", input[0], "\n");
			return (-1);
		}
	}
	wait(&pid);
	return (1);
}

int	execution(char **commands)
{
	int		i;
	int		ret;
	char	**cmd;

	i = -1;
	while (commands && commands[++i])
	{
		cmd = ft_strsplits(commands[i]);
		ret = check_one_cmd(cmd);
		if (!ret)
			ft_put4str("my_sh: ", "command not found: ", cmd[0], "\n");
		ft_free(&cmd);
		if (ret == -1)
			break ;
	}
	return (ret);
}
