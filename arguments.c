/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:06:46 by eduarodr          #+#    #+#             */
/*   Updated: 2023/06/22 15:23:06 by eduardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argument1(t_pipe pip, char **env, int *fd, char **av)
{
	char	*getp;
	char	**command;

	command = ft_split(av[2], ' ');
	getp = get_path(command[0], env);
	if (dup2(pip.file1, STDIN_FILENO) < 0)
	{
		close_all(fd, 0, getp, command);
		close(fd[1]);
	}
	if (dup2(fd[1], STDOUT_FILENO) < 0)
	{
		close_all(fd, 0, getp, command);
		close(fd[1]);
	}
	close(fd[1]);
	close(pip.file1);
	if (getp)
		execve(getp, command, env);
	close(fd[1]);
	close_all(fd, 0, getp, command);
}

int	pipex(char **av, char **env, t_pipe pip)
{
	int	fd[2];
	int	id;
	int	id2;
	int	return_value;

	pipe(fd);
	id = fork();
	if (id < 0)
		exit(write(1, "\e[0;31m Error creating fork!\e[0;31m", 36));
	if (id == 0)
		argument1(pip, env, fd, av);
	id2 = fork();
	if (id2 < 0)
		exit(write(1, "Error creating second fork!", 28));
	if (id2 == 0)
		argument2(pip, env, fd, av);
	close(fd[0]);
	close(fd[1]);
	close(pip.file1);
	close(pip.file2);
	waitpid(id, &return_value, 0);
	waitpid(id2, &return_value, 0);
	return (return_value);
}

void	argument2(t_pipe pip, char **env, int *fd, char **av)
{
	char	*getp;
	char	**command;

	command = ft_split(av[3], ' ');
	getp = get_path(command[0], env);
	if (dup2(pip.file2, STDOUT_FILENO) < 0)
	{
		close_all(fd, 1, getp, command);
		close(fd[0]);
	}
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		close_all(fd, 1, getp, command);
		close(fd[0]);
	}
	close(fd[0]);
	close(fd[1]);
	close(pip.file1);
	close(pip.file2);
	if (getp)
		execve(getp, command, env);
	close(fd[1]);
	close_all(fd, 0, getp, command);
}

char	*get_path(char *command, char **env)
{
	int		i;
	char	**path;
	char	*str;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = ft_split(env[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		str = triple_strjoin(path[i++], "/", command);
		if (!access(str, F_OK))
			break ;
		free(str);
		str = NULL;
	}
	if (!str)
		perror("\e[0;31m Command path not found\e[0;37m");
	free_path(path);
	return (str);
}

void	free_path(char **list)
{
	int	i;

	if (list)
	{
		i = 0;
		while (list[i])
			free(list[i++]);
		free(list);
	}
}
