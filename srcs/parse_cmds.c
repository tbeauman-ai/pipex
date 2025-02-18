/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:06:47 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 16:59:46 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	assign(char ***addr, char **cmd, char ***args, char **tmp)
{
	*addr = tmp;
	*cmd = tmp[0];
	*args = tmp + 1;
}

void	parse_cmds(char **av, t_env *pipex)
{
	char	**tmp;

	tmp = ft_split(av[2], ' ');
	if (!tmp || !tmp[0])
	{
		if (tmp)
			free(tmp);
		exit(EXIT_FAILURE);
	}
	assign(&pipex->addr1, &pipex->cmd1, &pipex->argscmd1, tmp);
	tmp = ft_split(av[3], ' ');
	if (!tmp || !tmp[0])
	{
		if (tmp)
			free(tmp);
		free_tab(pipex->addr1);
		ft_putstr_fd("Memory allocation error\n", 2);
		exit(EXIT_FAILURE);
	}
	assign(&pipex->addr2, &pipex->cmd2, &pipex->argscmd2, tmp);
}
