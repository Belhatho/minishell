/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:14:11 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:14:12 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../inc/minishell.h"


int		check_one_cmd(char **input, t_env **m_env)
{
		int				x;
		struct stat		st;

		x = is_builtin(input, m_env);
		if (x == -1)
			return (-1);
		if (x == 1 || is_bin(input, *m_env))
			return (1);
		//ft_putstr("**NO BINS**\n");
		if (lstat(input[0], &st) != -1)
			return(check_exec(input[0], st, input, *m_env));
		return (0);
}


int	exexcution(char **commands, t_env env)
{
	int i;
	char	**cmd;

	i = -1;
	while (commands[++i])
	{
		cmd = ft_strsplits(commands);

	}
}

