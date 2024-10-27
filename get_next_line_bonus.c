/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:20:28 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/04 13:58:35 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*next_line;

	if (fd < 0)
		return (NULL);
	if (((storage[fd] && !ft_strchr(storage[fd], '\n')) || !storage[fd]))
		storage[fd] = readbuf(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	next_line = ft_next_line(storage[fd]);
	if (!next_line)
		return (ft_free(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (next_line);
}

char	*readbuf(int fd, char *storage)
{
	int		i;
	char	*buf;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&storage));
	buf[0] = '\0';
	while (i > 0 && !ft_strchr(buf, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i > 0)
		{
			buf[i] = '\0';
			storage = ft_strjoin(storage, buf);
		}
	}
	free(buf);
	if (i == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*ft_next_line(char *storage)
{
	char		*line;
	char		*str;
	int			len;

	str = ft_strchr(storage, '\n');
	len = (str - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*str;
	int		len;

	str = ft_strchr(storage, '\n');
	if (!str)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (str - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (*str);
}

/* int	main(void)
{
	int		char_reads;
	char	buf[256];
	int		fd = open("archivo.txt", O_RDONLY);
	int		fd2 = open("archivo2.txt", O_RDONLY);
	int		fd3 = open("archivo3.txt", O_RDONLY);

	int i = 0;

	while (i < 12)
	{
		printf("line%d = %s", i, get_next_line(fd));
		printf("line%d = %s", ++i, get_next_line(fd2));
		printf("line%d = %s\n", ++i, get_next_line(fd3));
		//buf[char_reads] = '\0';
		//printf("i = %d, %s\n", i, buf);
		i++;
	}
	return (0);
} */
//gcc get_next_line_bonus.c get_next_line_utils_bonus.c