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

void	free_exit(t_env m_env)
{
	ft_free(&m_env.vars);
	write(1, "\n", 1);
	exit(0);
}

void	prompt()
{
	// char    *pwd;
	// char	buff[4097];
	//pwd = getcwd(buff, 4096);
	//printf("\n\t--PWD$ %s\n", pwd);
	ft_put3str("\033[33m", "my_sh $", "\033[0m ");
}

char	*parse_dollar(char *input, int index, t_env m_env)
{
	char	*key;
	char	*val;
	int		len;
	int		i;

	len = 0;
	i = index - 1;
	while (input[++i] && input[i] != ' ' && input[i] != '$')
		len++;
	key = ft_memalloc(len + 1);
	i = -1;
	while (++i < len)
		key[i] = input[index + i];
	key[i] = '\0';
	printf("**KEY: %s", key);
	val = get_var(key, m_env);
	free(key);
	return (val);
}

char	*parser(char **in, t_env env)
{
	int	i;
	char	*ret;
	char	*input;
	char	*tmp;

	i = -1;
	ret = ft_strnew(0);
	input = ft_strdup(*in);
	ft_strdel(in);
	if ((ft_strchr(input, '$') != NULL) || (ft_strchr(input, '~') != NULL))
	{
		while (input[++i])
		{
			if (input[i] == '$' && input[i + 1])
			{
				ft_putstr("\n** $ **\n");
				while (input[i] == '$' && input[i + 1])
					i++;
				tmp = parse_dollar(input, i, env);
				ret = ft_strjoin2(ret, tmp, 0);
				while (input[i + 1] && input[i + 1] != '$' && input[i] != ' ')
					i++;
				if (input[i - 1 == ' '])
					i--;
			}
			// 	else if (input[i] == '~' && ( i == 0 || (i != 0 && input[i - 1] != ' ')))
			// 	{
						// ft_putstr("\n** ~ **\n");
			// 		ret = ft_strjoin2(ret, )
			// 	}
			else
				ret = ft_strchjoin(ret, input[i]);
		}
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
	ft_put3str("\nhandlerInput:\t",*input, "\n");
	*input = parser(input, m_env);

}

void tests(t_env m_env)
{
	ft_putstr("\n***ENVIRONMENT***\n\n");
	print_env(m_env);
	// printf("\n***GET VARS***\n\nHOME\t%s\nPWD\t%s\nPATH\t%s\n/_\t%s\n"
	// 		, get_var("HOME", m_env),	get_var("PWD", m_env),\
	// 		get_var("PATH", m_env), get_var("_", m_env));
}

int main(int ac, char **av, char **env)
{
	t_env	m_env;
	char	*input;

	input = NULL;
	m_env = init_environment(ac, av, env);

	// tests(m_env);

	while (1)
	{
		prompt();
		input_handler(&input, m_env);
		ft_put3str("\n-INPUT-\t:",input, "\n");
	}

	return (0);
}
