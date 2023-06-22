/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:51:39 by eduarodr          #+#    #+#             */
/*   Updated: 2023/06/22 14:33:50 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
    t_pipe  pip;

    if(ac != 5)
    {
        write(1, "Invalid number of arguments.\n", 30);
        return(1);
    }
    pip.file1 = open(av[1], O_RDONLY);
    if (pip.file1 <= 0)
        return(write(1, "\e[0;31mFile not found!\n\e[0;37m", 31));
    pip.file2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (pip.file2 <= 0)
    {
        close(pip.file1);
        return(write(1, "\e[0;31m Error creating file!\e[0;37m", 30));
    }
    pipex(av, env, pip);
}
