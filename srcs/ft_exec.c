/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:22:31 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 13:46:03 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char    *find_path(char *cmd, char **envp)
// {
//     char    **paths;
//     char    *path;
//     int     i;
//     char    *part_path;

//     i = 0;
// }

// void    execute(t_env *pipex)
// {
//     char    **cmd;
//     int     i;
//     char    *path;

//     i = -1;
//     cmd = ft_split()   
// }

// void    ft_exec(t_env *pipex)
// {
//     int     fd[2];
//     pid_t   pid;

//     if (pipe(fd) == -1)
//     {
//         perror("pipe error\n");
//         exit(EXIT_FAILURE);
//     }

//     pid = fork();
//     if (pid == -1)
//     {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (pid == CHILD)
//     {
//         dup2(fd[1], STDOUT_FILENO);
//         pipex->in_fd = open(pipex->infile, O_RDONLY);
//         if (pipex->in_fd == -1)
//         {
//             cleanup(pipex);
//             exit(EXIT_FAILURE);
//         }
//         close(fd[0]);
//         execute(pipex);
//     }
//     else
//     {
//         wait(NULL);
//         pipex->out_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
//         if (pipex->out_fd == -1)
//         {
//             cleanup(pipex);
//             exit(EXIT_FAILURE);
//         }
//         dup2(fd[0], STDIN_FILENO);
//         dup2(pipex->out_fd, STDOUT_FILENO);
//         close(fd[1]);
//         execute(pipex);
//     }
// }