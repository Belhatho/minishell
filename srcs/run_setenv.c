/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:14:54 by belhatho          #+#    #+#             */
/*   Updated: 2022/01/18 22:14:55 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

int     run_setenv(char **input, t_env m_env)
{
    int     len;

    len = ft_strlen2(input);
    if (len == 1)
        print_env(m_env);
    else if (len == 2)
        set_var(input[1], "", m_env);
    else if (len == 3)
        set_var(input[1], input[2], m_env);
    else
        ft_putstr("setenv: Too many arguments.\n");
    return (1);
}
