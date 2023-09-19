/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:59:49 by siroulea          #+#    #+#             */
/*   Updated: 2023/09/19 13:00:32 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	child0(int argc, char **argv, char **env, int *fd, int i)
{
	int	file;

	file = open(argv[0], O_RDONLY, 0666);
	if (file == -1)
	{
		perror("error open files");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(file, 0);
	close(file);
	do_cmd(argv[i], env);
	exit(1);
}

void	child1(int argc, char **argv, char **env, int *fd, int i)
{
	int	file;

	file = open(argv[0], O_RDONLY, 0666);
	if (file == -1)
	{
		perror("error open/new file");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(file, 1);
	close(file);
	do_cmd(argv[i], env);
	exit(1);
}
char	*found_path(char *argv, char **env)
{
	char	**pathlist;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	//temp que mon environement n'est pas == path
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	pathlist = ft_split(env[i], ':');
	i = 0;
	while (pathlist[i])
	{
		//rajoute un / a la fin de mon path
		temp = ft_strjoin(pathlist[i++], "/");
		//rajoute le argv apres "qui est l'executable d'un programe"
		path = ft_strjoin(temp, argv);
		//si il trouve mon lexecutable dans le path retourne le path
		if (access(path, F_OK) == 0)
		{
			ft_free(*pathlist);
			return (path);
		}
	}
	return (0);
}

void	do_cmd(char *argv, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	//je fait un ft split pour enlenver un -l dans(ls -l) exemples
	cmd = ft_split(argv, 32);
	if (!cmd)
	{
		free(cmd);
		perror("no command");
		exit(EXIT_FAILURE);
	}
	//trouve mon path
	path = found_path(cmd[0], env);
	if (!path)
	{
		ft_free(path);
		perror("Command path not found");
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("execve error");
		exit(EXIT_FAILURE);
	}
	return ;
}