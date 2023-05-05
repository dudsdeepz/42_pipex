/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:03:45 by eduarodr          #+#    #+#             */
/*   Updated: 2023/05/05 14:30:02 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
 #define PIPXEX_h

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_pipe{
    int file1;
    int cmd1;
    int file2;
    int cmd2;
    char *envpath;
}   t_pipe  ;


void argument2(t_pipe pip, char **env, int *fd, char **av);
void pipex(char **av, char **env, t_pipe pip);
char get_path(char **av, char **env);
void argument1(t_pipe pip, char **env, int *fd, char **av);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	**recursive(char **split, int count, char c, char const *s);

#endif

