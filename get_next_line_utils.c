/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:30:11 by jesroble          #+#    #+#             */
/*   Updated: 2024/01/25 10:12:29 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//c -1 is to start the while loop on ++c = 0

char	*ft_strjoin(char *s1, char *s2)
{
	char		*s3;
	size_t		c;
	size_t		i;

	c = -1;
	i = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	s3 = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (ft_free(&s1));
	while (s1[++c])
		s3[c] = s1[c];
	while (s2[++i])
		s3[c + i] = s2[i];
	s3[c + i] = '\0';
	free(s1);
	return (s3);
}

size_t	ft_strlen(char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char) c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		substring = malloc(sizeof(char) * (1));
		if (!substring)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}
