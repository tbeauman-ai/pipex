/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:38:04 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 17:00:00 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_path(char *cmd, char **paths, t_env *pipex)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	path = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			exit_clean(pipex, EXIT_FAILURE);
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		tmp = 0;
		if (!path)
			exit_clean(pipex, EXIT_FAILURE);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		path = 0;
		i++;
	}
	free_tab(paths);
	return (0);
}

char	*find_path(char *cmd, char **envp, t_env *pipex)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		exit_clean(pipex, EXIT_FAILURE);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		exit_clean(pipex, EXIT_FAILURE);
	return (join_path(cmd, paths, pipex));
}
