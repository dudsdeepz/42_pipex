/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:25:58 by eduarodr          #+#    #+#             */
/*   Updated: 2023/06/07 12:06:28 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wdc(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

size_t	word_size(const char *str, int n, char c)
{
	size_t	i;

	i = 0;
	while (str[++n] && str[n] != c)
		i ++;
	return (i);
}

char	**ft_split(const char *str, char c)
{
	char	**ret;
	int		size;
	int		j;
	int		i;
	
	i = 0;
	j = -1;
	size = wdc(str, c);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	while (++j < size)
	{
		while (str[i] && str[i] == c)
			i ++;
		if (str[i] && str[i] != c)
			ret[j] = ft_substr(str, i, word_size(str, i - 1, c));
		while (str[i] && str[i] != c)
			i ++;
	}
	return (ret);
}

char	*ft_substr(char const *s, int start, int len)
{
	char		*substring;
	size_t		i;

	i = ft_strlen(s);
	if (!(s))
		return (NULL);
	if (start >= i)
		len = 0;
	else if (len > (i - start))
		len = i - start;
	substring = malloc(len + 1);
	if (!(substring))
		return (NULL);
	substring[len] = '\0';
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
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
