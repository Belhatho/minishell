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

# include "minishell.h"

int		run(char *cmd, char **input)
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
		if (execve(cmd, input, m_env) == -1)
		{
			ft_put3str("my_sh: command not found: ", input[0], "\n");
			return (-1);
		}
	}
	wait(&pid);
	return (1);
}

int		check_exec(char *path, struct stat st, char **input)
{
	if (st.st_mode & S_IFREG)
	{
		if (st.st_mode & S_IEXEC)
			return (run(path, input));
		else
			ft_put3str("my_sh: permision denied: ", input[0], "\n");	
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
		return(check_exec(input[0], st, input)); //check if dir
	return (0);
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
			ft_put3str("my_sh: ", "command not found: ", cmd[0]);
		ft_free(&cmd);
		if (ret == -1)
			break;
	}
	return (ret);
}
