/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:06:46 by eduarodr          #+#    #+#             */
/*   Updated: 2023/05/05 14:44:46 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void argument1(t_pipe pip, char **env, int *fd, char **av)
// {
//     int getp;
//     char **command;

//     command = ft_split(av[2], " ");
//     dup2(pip.file1, STDIN_FILENO);
//     dup2(fd[1], STDOUT_FILENO);
//     close(fd[0]);
//     getp = get_path(av, env);
//     execve(getp, command, env);
//     close(pip.file1);
// }

// void pipex(char **av, char **env, t_pipe pip)
// {
//     int fd[2];
//     int id;
//     int id2;

//     if (pip.file1 < 0 || pip.file2 < 0)
//         exit(-1);
//     pipe(fd);
//     id = fork();
//     if (id < 0)
//         return(perror("Error creating fork!"));
//     if (id == 0)
//         argument1(pip, env, fd, av);
//     wait(0);
//     id2 = fork();
//     if (id2 < 0)
//         return(perror("Error creating second fork!"));
//     if (id2 == 0)
//         argument2(pip, env, fd, av);
// }

// void argument2(t_pipe pip, char **env, int *fd, char **av)
// {
//     int getp;
//     char **command;

//     command = ft_split(av[2], " ");
//     dup2(pip.file2, STDOUT_FILENO);
//     dup2(fd[0], STDIN_FILENO);
//     close(fd[1]);
//     getp = get_path(av, env);
//     execve(getp, command, env);
//     close(pip.file2);
// }

char get_path(char **av, char **env)
{
    int i;
    char *env_path;
    char **path;

    i = 0;
    while (env[++i])
        if(!ft_strncmp(env[i], "PATH=", 5))
            env_path = env[i];
    i = 0;
    printf("%s\n", ft_split(env_path, ':'));
    // while(env_path[++i])
    //     if (env_path[i] == ':')
    //         printf(":\n");
}