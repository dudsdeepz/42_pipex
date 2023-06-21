/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:51:39 by eduarodr          #+#    #+#             */
/*   Updated: 2023/06/21 16:27:18 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int main(int ac, char **av, char **env)
{
    t_pipe pip;

    if(ac != 5)
    {
        write(1, "Invalid number of arguments.\n", 30);
        return (1);
    }
    pipex(av, env, pip);
}
