/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:19:03 by belhatho          #+#    #+#             */
/*   Updated: 2022/02/25 04:35:12 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../inc/minishell.h"

// static int		is_bin(char **input, t_env m_env)
// {
// 	struct stat st;
// 	char		**path;
// 	char		*exc;
// 	int			i;

// 	i = 0;
// 	path = ft_strsplit(get_var("PATH", m_env), ':');
// 	while (path && path[i])
// 	{
// 		if (is_first_word(path[i], input[0]))
// 			exc = ft_strdup(input[0]);
// 		else
// 			exc = do_path(path[i], input[0]);
// 		if (lstat(exc, &st) != -1)
// 		{
// 			if (check_exec(exc, st, input, m_env))
// 			{
// 				ft_strdel(&exc);
// 				free_tab(&path);
// 				return (1);
// 			}
// 		}
// 		ft_strdel(&exc);
// 		i++;
// 	}
// 	free_tab(&path);
// 	return (0);
// }

static int	is_builtin(char **cmd, t_env env)
{
	if (ft_strequ(cmd[0], "exit"))
		return (-1);
	else if (ft_strequ(cmd[0], "env"))
		return (print_env(env));
// 	if (ft_strequ(cmd[0], "setenv"))
// 		return (run_setenv(input, m_env));
// 	if (ft_strequ(cmd[0], "unsetenv"))
// 		return (run_unsetenv(input, m_env));
// 	if (ft_strequ(cmd[0], "cd"))
// 		return (run_cd(input, m_env));
// //	if (ft_strequ(cmd[0], "echo"))
//		return (run_echo(input, m_env));
	return (0);
}

int		check_one_cmd(char **input, t_env m_env)
{
		int				isbuiltin;
		// struct stat		st;

		isbuiltin = is_builtin(input, m_env);
		return(isbuiltin);
		// if (isbuiltin == -1)
		// 	return (-1);
		// if (isbuiltin == 1 || is_bin(input, m_env))
		// 	return (1);
		// if (lstat(input[0], &st) != -1)
		// 	return(check_exec(input[0], st, input, m_env));
		// if only spaces in input!!! 
		return (0);
}


int	execution(char **commands, t_env env)
{
	int i;
	int	ret;
	char	**cmd;
	

	i = -1;
	while (commands && commands[++i])
	{
		printf("\n***CMDS[%d]: %s ***\n",i,commands[i]);
		cmd = ft_strsplits(commands[i]);
		ret = check_one_cmd(cmd, env);
		if (!ret)
			ft_put3str("my_sh: ", "command not found: ", cmd[0]);
		ft_free(&cmd);
		if (ret == -1)
			break;
		
	}
	return (ret);
}
