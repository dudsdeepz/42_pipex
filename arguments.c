/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:06:46 by eduarodr          #+#    #+#             */
/*   Updated: 2023/06/21 16:49:20 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void argument1(t_pipe pip, char **env, int *fd, char **av)
{
    char  *getp;
    char **command;

    close(fd[0]);
    command = ft_split(av[2], ' ');
    dup2(pip.file1, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    getp = get_path(av[2], env);
    execve(getp, command, env);
    free(getp);
    free_path(command);
    close(fd[1]);
    exit(1);
}

void pipex(char **av, char **env, t_pipe pip)
{
    int fd[2];
    int id;
    int id2;

    pip.file1 = open(av[1], O_RDONLY);
    if (pip.file1 <= 0)
        return(perror("\e[0;31mError\e[0;37m"));
    pip.file2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (pip.file2 <= 0)
        return(perror("\e[0;31m Error\e[0;37m"));
    pipe(fd);
    id = fork();
    if (id < 0)
        return(perror("\e[0;31m Error creating fork!\e[0;31m"));
    if (id == 0)
        argument1(pip, env, fd, av);
    wait(0);
    id2 = fork();
    if (id2 < 0)
        return(perror("Error creating second fork!"));
    if (id2 == 0)
        argument2(pip, env, fd, av);
    close(pip.file1);
    close(pip.file2);
}

void argument2(t_pipe pip, char **env, int *fd, char **av)
{
    char *getp;
    char **command;

    close(fd[1]);
    command = ft_split(av[2], ' ');
    dup2(pip.file2, STDOUT_FILENO);
    dup2(fd[0], STDIN_FILENO);
    getp = get_path(av[3], env);
    execve(getp, command, env);
    free(getp);
    free_path(command);
    close(fd[0]);
    exit(1);
}

char *get_path(char *command, char **env)
{
    int i;
    char **path;
    char *str;

    i = 0;
    while (ft_strncmp(env[i], "PATH=", 5))
        i++;
    path = ft_split(env[i] + 5, ':');
    i = 0;
    while (path[i])
    {
        str = triple_strjoin(path[i++], "/", command);
        if (!access(str, F_OK))
            break;
        free(str);
        str = NULL;
    }
    if (!str)
        perror("\e[0;31m Command path not found\e[0;37m");
    free_path(path);
    return(str);
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
