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

char	*parse_home(char *path, int rev)
{
	char	*home_path;
	char	*ret;

	if (!path)
		return (NULL);
	home_path = get_var("HOME");
	if (rev && !ft_strstartswith(path, "~"))
		return (ft_strdup(path));
	if (!rev && !ft_strstartswith(path, home_path))
		return (ft_strdup(path));
	// if (!ft_strstartswith(path, rev ? "~" : home_path))
	// 	return (ft_strdup(path));
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

char	*parse_dollar(char *input, int index)
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
	val = get_var(key);
	if (!val)
	{
		free(key);
		return (NULL);
	}
	free(key);
	return (val);
}

char	*parser(char *in)
{
	int		i;
	char	*ret;

	i = -1;
	ret = ft_strnew(0);
	if ((ft_strchr(in, '$') != NULL) || (ft_strchr(in, '~') != NULL))
	{
		while (in[++i])
		{
			if (in[i] == '$' && in[i + 1])
			{
				ret = ft_strjoin(ret, parse_dollar(in, i + 1));
				while (in[i + 1] && !isspce(in[i + 1]) && in[i + 1] != '$')
					i++;
			}
			else if (in[i] == '~' && ((i != 0 && isspce(in[i - 1])) || i == 0))
				ret = do_path(ret, ft_strchjoin(get_var("HOME"), '/'));
			else
				ret = ft_strchjoin(ret, in[i]);
		}
		free(in);
		return (ret);
	}
	return (in);
}
