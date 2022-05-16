/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:13:33 by belhatho          #+#    #+#             */
/*   Updated: 2022/05/12 04:06:12 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	char	*pwd;
	char	buff[4097];

	pwd = getcwd(buff, 4096);
	ft_put4str("\033[1;36m", get_var("USER"), "@\033[1;34m", "my_sh");
	if (!pwd)
		ft_put3str("\033[1;31m ", "?", "\033[0;33m $ \033[0m");
	else if (!ft_strcmp(pwd, get_var("HOME")))
		ft_put3str("\033[1;31m ", "~", "\033[0;33m $ \033[0m");
	else
		ft_put3str("\033[1;31m ", ft_strechr(pwd, '/') + 1, \
			"\033[0;33m $ \033[0m");
}

char	*input_handler(void)
{
	char	*input;
	char	buf;
	int		nbr_oct;
	int		i[2];

	input = ft_strnew(0);
	i[0] = 0;
	i[1] = 1;
	nbr_oct = read(0, &buf, 1);
	while (nbr_oct && buf != '\n')
	{
		*(input + i[0]++) = buf;
		input = ft_realloc((void **)(&input), i[1], i[1] + 1);
		i[1]++;
		nbr_oct = read(0, &buf, 1);
	}
	*(input + i[0]) = '\0';
	if (!nbr_oct)
	{
		free(input);
		free_exit();
	}
	if ((ft_strchr((input), '$') != NULL) || (ft_strchr((input), '~') != NULL))
		parser(&input);
	return (input);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	**cmds;

	input = NULL;
	init_environment(ac, av, env);
	while (1)
	{
		prompt();
		signal(SIGINT, ft_signal);
		input = input_handler();
		if (ft_isempty(&input))
			continue ;
		cmds = ft_strsplit(input, ';');
		free(input);
		if (execution(&cmds) == -1)
		{
			ft_putendl("\033[0;31m my_sh terminated.\033[0m");
			break ;
		}
	}
	ft_free(&g_env);
	return (0);
}
