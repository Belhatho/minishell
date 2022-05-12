/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 04:34:07 by belhatho          #+#    #+#             */
/*   Updated: 2022/05/12 04:30:12 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isspce(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	free_exit(void)
{
	ft_free(&g_env);
	write(1, "\n", 1);
	exit(0);
}

char	*strreplace(char *haystack, char *needle, char *str)
{
	char	*tmp;
	char	*tmp2;
	char	*p1;
	char	*ret;

	tmp = ft_strstr(haystack, needle);
	if (!tmp)
		return (NULL);
	p1 = ft_strsub(haystack, 0, ft_strlen(haystack) - ft_strlen(tmp));
	tmp2 = ft_strjoin(p1, str);
	ret = ft_strjoin(tmp2, &tmp[ft_strlen(needle)]);
	free(p1);
	free(tmp2);
	return (ret);
}
