/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:25:58 by eduarodr          #+#    #+#             */
/*   Updated: 2023/05/05 14:44:26 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**recursive(char **split, int count, char c, char const *s)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (s && *s && *s == c)
		s++;
	while (*s && s[i] && s[i] != c)
		i++;
	if (i > 0)
		str = malloc(sizeof(char) * i + 1);
	if (str)
		str[i] = '\0';
	while (str && s && *s && *s != c)
		str[i++] = *s++;
	if (str)
		split = recursive(split, count + 1, c, s);
	else
		split = malloc(sizeof(char *) * (count + 1));
	if (split)
		split[count] = str;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	return (recursive(NULL, 0, c, s));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] == s1[i] && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}