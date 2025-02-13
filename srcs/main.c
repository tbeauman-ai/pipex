/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:14:41 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 13:53:57 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     main(int ac, char **av, char **envp)
{
    // t_env   pipex;

    // init(&pipex, envp);
    // check_args(ac, av, &pipex);
    // parse_cmds(ac, av, &pipex);
    // parse_files(ac, av, &pipex);
    // ft_exec(&pipex, envp);
    // cleanup(&pipex);
    // close(pipex.in_fd);
    // close(pipex.out_fd);
    int     i;

    i = 0;
    unsetenv("PATH");
    (void)ac;
    (void)av;
    while (envp[i])
        ft_printf("%s\n", envp[i++]);

    return (1);
}