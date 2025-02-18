/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:45:52 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 17:06:27 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_env
{
	char	*infile;
	char	*outfile;
	int		in_fd;
	int		out_fd;
	char	*cmd1;
	char	**argscmd1;
	char	**addr1;
	char	*cmd2;
	char	**argscmd2;
	char	**addr2;
	char	**envp;
	int		error_flag;
}			t_env;

#endif