/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:31:08 by eduarodr          #+#    #+#             */
/*   Updated: 2023/06/22 15:21:45 by eduardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*triple_strjoin(char *s1, char *s2, char *s3)
{
	char	*res;
	int		i;

	i = 0;
	if (!s1 || !s2 || !s3)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	while (*s3)
		res[i++] = *s3++;
	res[i] = 0;
	return (res);
}

size_t	ft_strlen(const char *str)

{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	close_all(int *fd, int i, char *getp, char **comand)
{
	free(getp);
	free_path(comand);
	close(fd[i]);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(1);
}
