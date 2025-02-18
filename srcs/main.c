/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:14:41 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 17:08:20 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_env	pipex;

	init(&pipex, envp);
	check_args(ac, av, &pipex);
	parse_cmds(av, &pipex);
	parse_files(ac, av, &pipex);
	process(&pipex);
	return (0);
}
