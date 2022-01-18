/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:13:33 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:21:25 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

void	exit_sh(t_env m_env)
{
	ft_free(&m_env.vars);
	write(1, "\n", 1);
	exit(0);
}

void	display_prompt()
{
    char    *pwd;
    char	buff[4097];
    //pwd = getcwd(buff, 4096);
    //printf("\n\t--PWD$ %s\n", pwd);
    ft_putstr("my.sh>>$ ");
}


	int		ret;
	char	buf;
	int		i;
	int		count;

	*input = ft_strnew(1);
	count = 1;
	i = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = ft_realloc(*input, count, count + 1);
		count++;
	}
	*(*input + i) = '\0';
	if (!ret)
	{
		free(*input);
		exit_shell();
	}
	if ((ft_strchr(*input, '$') != NULL) || (ft_strchr(*input, '~') != NULL))
		*input = parse_input(*input);


int main(int ac, char **av, char **env)
{
	t_env	m_env;
	char	*input;


	m_env = init_environment(ac, av, env);
	while (1)
	{
		
	}
	
	return (0);
}
