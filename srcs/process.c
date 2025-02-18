/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:22:31 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 17:08:11 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_child_process(t_env *pipex, int fd[2])
{
	if (pipex->in_fd != -1)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipex->in_fd, STDIN_FILENO);
		close(fd[0]);
		execute(pipex->cmd1, pipex->argscmd1, pipex);
	}
}

static void	second_child_process(t_env *pipex, int fd[2])
{
	if (pipex->out_fd != -1)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(pipex->out_fd, STDOUT_FILENO);
		close(fd[1]);
		execute(pipex->cmd2, pipex->argscmd2, pipex);
	}
}

static void	parent_process(t_env *pipex, int fd[2], pid_t pid1, pid_t pid2)
{
	close(fd[0]);
	close(fd[1]);
	if (waitpid(pid1, NULL, 0) == -1)
		exit_clean(pipex, EXIT_FAILURE);
	if (waitpid(pid2, NULL, 0) == -1)
		exit_clean(pipex, EXIT_FAILURE);
	cleanup(pipex);
	if (pipex->error_flag)
		exit(pipex->error_flag);
}

void	process(t_env *pipex)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	pipex->in_fd = open(pipex->infile, O_RDONLY);
	if (pipex->in_fd == -1)
		pipex->error_flag = 1;
	pipex->out_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->out_fd == -1)
		pipex->error_flag = 1;
	if (pipe(fd) == -1)
		exit_clean(pipex, EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		exit_clean(pipex, EXIT_FAILURE);
	else if (pid1 == 0)
		first_child_process(pipex, fd);
	pid2 = fork();
	if (pid2 == -1)
		exit_clean(pipex, EXIT_FAILURE);
	else if (pid2 == 0)
		second_child_process(pipex, fd);
	parent_process(pipex, fd, pid1, pid2);
}
