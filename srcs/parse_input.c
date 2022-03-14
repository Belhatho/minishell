 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:13:55 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:13:56 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	*parse_home(char *path, int rev, t_env *m_env)
{
	char	*home_path;
	char	*ret;

	if (!path)
		return (NULL);
	home_path = get_var("HOME", m_env);
	if (!ft_strstartswith(path, rev ? "~" : home_path))
		return (ft_strdup(path));
	if (rev)
		ret = do_path(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			ret = ft_strdup("~");
		else
			ret = do_path("~", path + ft_strlen(home_path));
	}
	return (ret);
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
	val = get_var(key, &m_env);
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
	int		i;
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
				while (input[i + 1] && !isspce(input[i + 1]) && input[i + 1] != '$')
					i++;
			}
			else if (input[i] == '~' && ((i != 0 && isspce(input[i - 1])) || i == 0))
			{
				ret = ft_strjoin(ret, parse_home(input + i, 1, &env));
				i += ft_strlen(input + i) - 1;
				// printf("\n-prse ~- %s !%s!\n", ret, input + i - 1);
			}
			else
				ret = ft_strchjoin(ret, input[i]);
		}
		free(input);
		return (ret);
	}
	return (input);
}
