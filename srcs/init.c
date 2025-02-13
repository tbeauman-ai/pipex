/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:47:13 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 13:36:35 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    init(t_env *pipex, char **envp)
{
    pipex->infile = 0;
    pipex->outfile = 0;
    pipex->cmd1 = 0;
    pipex->argscmd1 = 0;
    pipex->addr2 = 0;
    pipex->cmd2 = 0;
    pipex->argscmd2 = 0;
    pipex->addr2 = 0;
    pipex->envp = envp;
}