/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:15:16 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 13:45:41 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "typedefs.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define CHILD 0

void    check_args(int ac, char **av, t_env *pipex);
void    init(t_env *pipex, char **envp);
void    cleanup(t_env *pipex);
void    parse_cmds(int ac, char **av, t_env *pipex);
void    parse_files(int ac, char **av, t_env *pipex);

#endif