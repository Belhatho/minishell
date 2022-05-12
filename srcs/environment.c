/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:25:49 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:25:51 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_env(void)
{
	int	i;

	i = -1;
	if (!g_env || !g_env[0])
		return (0);
	while (g_env && g_env[++i])
		ft_putendl(g_env[i]);
	return (1);
}

void	init_environment(int ac, char **av, char **env)
{
	int	i;

	(void)ac;
	(void)av;
	i = -1;
	g_env = (char **)ft_memalloc(sizeof(char *) * (ft_strlen2(env) + 1));
	while (env[++i])
	{
		g_env[i] = ft_strdup(env[i]);
		if (!g_env[i])
			free_exit();
	}
	g_env[i] = NULL;
	ft_putendl("\033[0;33m my_sh strating ...\033[0m");
}

char	**realloc_env(int size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = -1;
	while (g_env && g_env[++i] && i < size)
	{
		new[i] = ft_strdup(g_env[i]);
		free(g_env[i]);
	}
	new[size] = NULL;
	free(g_env);
	g_env = NULL;
	return (new);
}
