/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:48:16 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:48 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av, t_env *pipex)
{
	if (ac != 5)
	{
		ft_putstr_fd("pipex requires 4 arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	(void)av;
	(void)pipex;
}
