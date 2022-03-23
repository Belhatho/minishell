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

void	prompt(void)
{
	// char    *pwd;
	// char	buff[4097];
	//pwd = getcwd(buff, 4096);
	//printf("\n\t--PWD$ %s\n", pwd);
	ft_put3str("\n\x1b[32;01m", "my_sh\033[1;31m $", "\033[0m ");
}

void tests(t_env m_env)
{
	// print_env(m_env);
	// ft_putstr("***ENVIRONMENT***\n\n");
	printf("\n***GET VARS***\n\nHOME\t%s\nPWD\t%s\nPATH\t%s\n/_\t%s\n", get_var("HOME", &m_env), get_var("PWD", &m_env),
		   get_var("PATH", &m_env), get_var("_", &m_env));
}

void	input_handler(char **input, t_env m_env)
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
		free_exit(m_env);
	}
	*input = parser(*input, m_env);
}

int	main(int ac, char **av, char **env)
{
	t_env	m_env;
	char	*input;
	char	**cmds;

	input = NULL;
	m_env = init_environment(ac, av, env);
	while (1)
	{
		// tests(m_env);
		prompt();
		signal(SIGINT, ft_signal);
		input_handler(&input, m_env);
		ft_put3str("-INPUT-\t:", input, "\n");
		if (ft_isempty(input, 1))
		{
			free(input);
			continue ;
		}
		cmds = ft_strsplit(input, ';');
		ft_strdel(&input);
		if (execution(cmds, &m_env) == -1)
		{
			ft_putendl("\033[1;31m my_sh terminated.\033[0m");
			break ;
		}
	}
	return (0);
}
