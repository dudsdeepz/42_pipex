/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:03:45 by eduarodr          #+#    #+#             */
/*   Updated: 2023/05/15 16:38:37 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
 #define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_pipe{
	int file1;
	int cmd1;
	int file2;
	int cmd2;
	char *envpath;
}	t_pipe  ;


void argument2(t_pipe pip, char **env, int *fd, char **av);
void pipex(char **av, char **env, t_pipe pip);
char *get_path(char *command, char **env);
void argument1(t_pipe pip, char **env, int *fd, char **av);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(const char *str, char c);
size_t	word_size(const char *str, int n, char c);
int	wdc(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
void	free_list(char **list);
char	*triple_strjoin(char *s1, char *s2, char *s3);
char	**recursive(char **split, int count, char c, char const *s);
size_t	ft_strlen(const char *str);

#endif

