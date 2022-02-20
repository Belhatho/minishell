/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:15:25 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:15:26 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"


#include<stdio.h>


typedef	struct s_env
{
	char	**vars;
	int		last_ret; //*moha*/
}				t_env;


t_env	init_environment(int ac, char **av, char **env);
void	print_env(t_env m_env);
char	*get_var(char *name, t_env m_env);

void	free_exit(t_env m_e);
#endif