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

void	input_handler(char **input)
{
	int		nbr_oct;
	char	buf;
	int		i;
	int		c;

	*input = ft_strnew(1);
	c = 1;
	i = 0;
	nbr_oct = read(0, &buf, 1);
	while (nbr_oct && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = ft_realloc((void **)(input), c, c + 1);
		c++;
		nbr_oct = read(0, &buf, 1);
	}
	*(*input + i) = '\0';
	if (!nbr_oct)
	{
		free(*input);
		free_exit();
	}
	*input = parser(*input);
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
		input_handler(&input);
		if (ft_isempty(input, 1))
		{
			free(input);
			continue ;
		}
		cmds = ft_strsplit(input, ';');
		ft_strdel(&input);
		if (execution(cmds) == -1)
		{
			ft_putendl("\033[0;31m my_sh terminated.\033[0m");
			break ;
		}
	}
	return (0);
}
