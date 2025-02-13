/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:17:52 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 13:43:34 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    parse_files(int ac, char **av, t_env *pipex)
{
    (void)ac;
    pipex->infile = ft_strdup(av[1]);
    if (!pipex->infile)
    {
        free(pipex->addr1);
        free(pipex->addr2);
        ft_putstr_fd("Memory allocation error\n", 2);
        exit(EXIT_FAILURE);
    }
    pipex->outfile = ft_strdup(av[4]);
    if (!pipex->outfile)
    {
        free(pipex->addr1);
        free(pipex->addr2);
        free(pipex->infile);
        ft_putstr_fd("Memory allocation error\n", 2);
        exit(EXIT_FAILURE);
    }
}