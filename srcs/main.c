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

# include "../inc/minishell.h"

int	isspce(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
void	free_exit(t_env m_env)
{
	// ft_free(&m_env.vars);
	write(1, "\n", 1);
	exit(0);
}

void	prompt()
{
	// char    *pwd;
	// char	buff[4097];
	//pwd = getcwd(buff, 4096);
	//printf("\n\t--PWD$ %s\n", pwd);
	ft_put3str("\n\033[33m", "my_sh $", "\033[0m ");
}

char	*parse_dollar(char *input, int index, t_env m_env)
{
	char	*key;
	char	*val;
	char	c;

	key = ft_strnew(1);
	while (input[index] && !isspce(input[index]) && input[index] != '$')
	{
		c = input[index];
		key = ft_strchjoinf(key, c);
		index++;
	}
	// ft_put2str("**KEY: ", key);
	val = get_var(key, m_env);
	if (!val)
	{
		free(key);
		return (NULL);
	}
	free(key);
	return (val);
}

char	*parser(char *input, t_env env)
{
	int	i;
	char	*ret;

	i = -1;
	ret = ft_strnew(0);
	if ((ft_strchr(input, '$') != NULL) || (ft_strchr(input, '~') != NULL))
	{
		while (input[++i])
		{
			if (input[i] == '$' && input[i + 1])
			{
				ret = ft_strjoin(ret, parse_dollar(input, i + 1, env));
				while (input[i + 1]  && !isspce(input[i + 1]) && input[i + 1] != '$')
					i++;
			}
			// 	else if (input[i] == '~' && ( i == 0 || (i != 0 && input[i - 1] != ' ')))
			// 	{
						// ft_putstr("\n** ~ **\n");
			// 		ret = ft_strjoin2(ret, )
			// 	}
			else
				ret = ft_strchjoin(ret, input[i]);
		}
		free(input);
		return (ret);
	}
	return(input);
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
	while ((nbr_oct = read(0, &buf, 1)) && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = ft_realloc(input, c, c + 1);
		c++;
	}
	*(*input + i) = '\0';
	if (!nbr_oct)
	{
		free(*input);
		free_exit(m_env);
	}
	// ft_put3str("\nhandlerInput:\t",*input, "\n");
	*input = parser(*input, m_env);

}

void tests(t_env m_env)
{
	print_env(m_env);
	ft_putstr("***ENVIRONMENT***\n\n");
	// printf("\n***GET VARS***\n\nHOME\t%s\nPWD\t%s\nPATH\t%s\n/_\t%s\n"
	// 		, get_var("HOME", m_env),	get_var("PWD", m_env),\
	// 		get_var("PATH", m_env), get_var("_", m_env));
}

int main(int ac, char **av, char **env)
{
	t_env	m_env;
	char	*input;
	char	**cmds;

	input = NULL;
	m_env = init_environment(ac, av, env);

	tests(m_env);
	while (1)
	{
int i = -1;
		prompt();
		input_handler(&input, m_env);
		ft_put3str("-INPUT-\t:",input, "\n");
		cmds = ft_strsplit(input, ';');
		ft_strdel(&input);
		if (execution(cmds, m_env) == -1)
		 	break;
	}

	return (0);
}
