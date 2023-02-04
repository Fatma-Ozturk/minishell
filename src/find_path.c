/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:27:37 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/08 19:11:29 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*verify_path_simple(char *cmd, int i)
{
	char	**holder;
	char	*aux;
	char	*current_path;
	char	*path;

	holder = ft_split(getenv("PATH"), ':');
	while (holder[++i])
	{
		aux = ft_strdup(holder[i]);
		holder[i] = ft_strjoin(aux, "/");
		path = ft_strjoin(holder[i], cmd);
		if (aux[0] != '\0')
			free(aux);
		if (!access(path, F_OK))
		{
			current_path = ft_strdup(path);
			free(path);
			ft_free_str(holder);
			return (current_path);
		}
		free(path);
	}
	ft_free_str(holder);
	return (NULL);
}

char	*find_path_simple(char *cmd)
{
	char	*path;

	path = NULL;
	if (!access(cmd, F_OK))
		return (cmd);
	path = verify_path_simple(cmd, -1);
	if (path != NULL)
		return (path);
	return (NULL);
}

char	*verify_path(char *cmd, int i)
{
	char	**holder;
	char	*aux;
	char	*path;
	char	*current_path;

	holder = ft_split(getenv("PATH"), ':');
	while (holder[++i])
	{
		aux = ft_strdup(holder[i]);
		holder[i] = ft_strjoin(aux, "/");
		path = ft_strjoin(holder[i], cmd);
		if (aux[0] != '\0')
			free(aux);
		if (!access(path, F_OK))
		{
			current_path = ft_strdup(path);
			free(path);
			ft_free_str(holder);
			return (current_path);
		}
		free(path);
	}
	ft_free_str(holder);
	return (NULL);
}

char	*find_path(char *cmd)
{
	char	*path;

	path = NULL;
	if (!access(cmd, F_OK))
		return (cmd);
	path = verify_path(cmd, -1);
	if (path[0] != '\0')
		return (path);
	return (NULL);
}
