/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:15:16 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 17:06:24 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "typedefs.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# define CHILD 0

void	check_args(int ac, char **av, t_env *pipex);
void	init(t_env *pipex, char **envp);
void	cleanup(t_env *pipex);
void	exit_clean(t_env *pipex, int exit_code);
void	free_tab(char **tab);
void	process(t_env *pipex);
void	parse_cmds(char **av, t_env *pipex);
void	parse_files(int ac, char **av, t_env *pipex);

char	**get_full_tab(char *cmd, char **args);
void	execute(char *cmd, char **args, t_env *pipex);

char	*join_path(char *cmd, char **paths, t_env *pipex);
char	*find_path(char *cmd, char **envp, t_env *pipex);

#endif