/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:06:46 by eduarodr          #+#    #+#             */
/*   Updated: 2023/05/05 17:05:00 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void argument1(t_pipe pip, char **env, int *fd, char **av)
{
    char  *getp;
    char **command;

    command = ft_split(av[2], ' ');
    dup2(pip.file1, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    getp = get_path(av[2], env);
    execve(getp, command, env);
    free(getp);
    free(command);
}

void pipex(char **av, char **env, t_pipe pip)
{
    int fd[2];
    int id;
    int id2;

    if (pip.file1 < 0 || pip.file2 < 0)
        exit(-1);
    pipe(fd);
    id = fork();
    if (id < 0)
        return(perror("Error creating fork!"));
    if (id == 0)
        argument1(pip, env, fd, av);
    wait(0);
    id2 = fork();
    if (id2 < 0)
        return(perror("Error creating second fork!"));
    if (id2 == 0)
        argument2(pip, env, fd, av);
}

void argument2(t_pipe pip, char **env, int *fd, char **av)
{
    char *getp;
    char **command;

    command = ft_split(av[2], ' ');
    dup2(pip.file2, STDOUT_FILENO);
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    getp = get_path(av[3], env);
    execve(getp, command, env);
    free(getp);
    free(command);
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
    {
        perror("Command not found");
    }
    free_list(path);
    return(str);
}

void	free_list(char **list)
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