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

char	**g_env;

void	prompt(void);

char	*parser(char *input);
char	*parse_home(char *path, int rev);
char	*do_path(char *name, char *d_name);

int		print_env(void);
void	init_environment(int ac, char **av, char **env);
char	**realloc_env(int size);

int		execution(char **commands);
int		run(char *cmd, char **input);
int		check_one_cmd(char **input);

int		run_cd(char **input);
void	ft_chdir(char *path, int print);
int		run_echo(char **input);
int		run_setenv(char **input);
int		run_unsetenv(char **input);
void	set_env_var(char *key, char *value);
char	*get_var(char *name);
int		find_var_index(char *var);

void	ft_signal(int sig);
void	ft_child_signal(int sig);

int		isspce(char c);
void	free_exit(void);

#endif