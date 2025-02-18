/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:20:49 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:34 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	cleanup(t_env *pipex)
{
	close(pipex->in_fd);
	close(pipex->out_fd);
	free(pipex->infile);
	free(pipex->outfile);
	free_tab(pipex->addr1);
	free_tab(pipex->addr2);
}

void	exit_clean(t_env *pipex, int exit_code)
{
	cleanup(pipex);
	exit(exit_code);
}
