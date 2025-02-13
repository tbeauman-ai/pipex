/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:20:49 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 11:21:51 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    cleanup(t_env *pipex)
{
    free(pipex->addr1);
    free(pipex->addr2);
    free(pipex->infile);
    free(pipex->outfile);
}