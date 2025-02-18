/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:26:24 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/18 17:03:51 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

char	**get_full_tab(char *cmd, char **args)
{
	char	**argex;
	int		i;

	argex = malloc(sizeof(char *) * (ft_tablen(args) + 2));
	if (!argex)
		return (NULL);
	argex[0] = ft_strdup(cmd);
	if (!argex[0])
		return (free(argex), NULL);
	i = 1;
	while (args[i - 1])
	{
		argex[i] = ft_strdup(args[i - 1]);
		if (!argex[i])
		{
			while (i-- > -1)
				free(argex[i]);
			return (free(argex), NULL);
		}
		i++;
	}
	argex[i] = NULL;
	return (argex);
}

void	execute(char *cmd, char **args, t_env *pipex)
{
	char	*path;
	char	**argex;

	path = find_path(cmd, pipex->envp, pipex);
	if (access(cmd, F_OK) == 0)
		path = ft_strdup(cmd);
	if (!path)
	{
		ft_putstr_fd("Command not found\n", 2);
		exit_clean(pipex, EXIT_FAILURE);
	}
	argex = get_full_tab(cmd, args);
	if (!argex)
	{
		free(path);
		exit_clean(pipex, EXIT_FAILURE);
	}
	if (execve(path, argex, pipex->envp) == -1)
	{
		free(path);
		free_tab(argex);
		exit_clean(pipex, EXIT_FAILURE);
	}
}
