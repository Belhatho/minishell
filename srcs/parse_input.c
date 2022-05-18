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

char	*parse_home(char *path)
{
	char	*home_path;
	char	*ret;

	if (!path)
		return (NULL);
	home_path = get_var("HOME");
	if ((!ft_strstartswith(path, "~")) || \
			(!ft_strstartswith(path, home_path)))
		return (ft_strdup (path));
	if (*(path + ft_strlen(home_path)) == '\0')
		ret = ft_strdup("~");
	else
		ret = do_path("~", path + ft_strlen(home_path));
	return (ret);
}

char	*parse_dollar(char *input, int index)
{
	char	*key;
	char	*val;
	char	c;

	key = ft_strnew(0);
	while (input[index] && !isspce(input[index]) \
	&& input[index] != ';' && input[index] != '$')
	{
		c = input[index];
		key = ft_strchjoinf(key, c);
		index++;
	}
	val = get_var(key);
	free(key);
	return (val);
}

char	*parsetilde(char *rt)
{
	char	*tmp;
	char	*ret;

	tmp = do_path(get_var("HOME"), "/");
	if (rt)
		ret = do_path(rt, tmp);
	else
		ret = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (ret);
}

char	*parse_expansions(char *rt, char *in, int *n)
{
	char	*ret;
	int		i;

	i = *n;
	ret = NULL;
	if (in[i] == '$' && in[i + 1])
	{
		ret = ft_strjoin(rt, parse_dollar(in, i + 1));
		while (in[i + 1] && !isspce(in[i + 1]) && in[i + 1] != '$'\
		&& in[i + 1] != ';')
			i++;
	}
	else if (in[i] == '~' && ((i != 0 && isspce(in[i - 1])) || i == 0))
		ret = parsetilde(rt);
	else
		ret = ft_strchjoin(rt, in[i]);
	free(rt);
	*n = i;
	return (ret);
}

void	parser(char **input)
{
	char	*ret;
	int		i;

	i = -1;
	ret = NULL;
	while ((*input) && (*input)[++i])
		ret = parse_expansions(ret, *input, &i);
	free(*input);
	*input = ft_strdup(ret);
	ft_strdel(&ret);
}
