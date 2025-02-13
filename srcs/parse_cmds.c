/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:06:47 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 13:43:00 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    parse_cmds(int ac, char **av, t_env *pipex)
{
    char    **tmp;

    (void)ac;
    tmp = ft_split(av[2], ' ');
    if (!tmp)
    {
        ft_putstr_fd("Memory allocation error\n", 2);
        exit(EXIT_FAILURE);
    }
    pipex->addr1 = tmp;
    pipex->cmd1 = tmp[0];
    pipex->argscmd1 = &tmp[1];
    tmp = ft_split(av[3], ' ');
    if (!tmp)
    {
        free(pipex->addr1);
        ft_putstr_fd("Memory allocation error\n", 2);
        exit(EXIT_FAILURE);
    }
    pipex->addr2 = tmp;
    pipex->cmd2 = tmp[0];
    pipex->argscmd2 = &tmp[1];
}