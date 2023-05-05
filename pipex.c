/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:03:43 by eduarodr          #+#    #+#             */
/*   Updated: 2023/05/05 14:14:07 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int ac, char **av, char **env)
{
    get_path(av, env);
        
    // t_pipe pip;
    
    // if(ac < 5)
    //     return (0);
    // pip.file1 = open(av[1], O_RDONLY);
    // pip.file2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    // pipex(av, env, pip);
}