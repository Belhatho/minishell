/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:13:33 by belhatho          #+#    #+#             */
/*   Updated: 2022/02/24 04:58:34 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt()
{
	char    *pwd;
	char	buff[4097];
	pwd = getcwd(buff, 4096);
	ft_put2str("\n\033[1;36m", get_var("USER"));
	ft_put2str("@\033[1;34m", ft_strechr(pwd, '/') + 1);
	ft_put2str("\033[1;31m my_sh\033[0;33m:$", "\033[0m ");
}

void tests(char** m_env)
{
	// print_env(m_env);
	// ft_putstr("***ENVIRONMENT***\n\n");
	printf("\n***GET VARS***\n\nHOME\t%s\nPWD\t%s\nPATH\t%s\n/_\t%s\n", 
	get_var("HOME"), get_var("PWD"), get_var("PATH"), get_var("_"));
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
		*input = ft_realloc(input, c, c + 1);
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
		// tests(m_env);
		prompt();
		signal(SIGINT, ft_signal);
		input_handler(&input);
		// ft_put3str("-INPUT-\t:", input, "\n");
		if (ft_isempty(input, 1))
		{
			free(input);
			continue ;
		}
		cmds = ft_strsplit(input, ';');
		ft_strdel(&input);
		if (execution(cmds) == -1)
		{
			ft_putendl("\033[1;31m my_sh terminated.\033[0m");
			break ;
		}
	}
	return (0);
}
