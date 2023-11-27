/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:59:22 by chmoussa          #+#    #+#             */
/*   Updated: 2023/06/21 14:41:17 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../fdf.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!GNL_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

/*
char	*ft_line(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 1) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*clean_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		safe_free(buffer);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (buffer[i])
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	safe_free(buffer);
	return (temp);
}

char	*ft_read(int fd, int *readed, char *temp)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (*readed != 0)
	{
		*readed = read(fd, buffer, BUFFER_SIZE);
		if (*readed == -1)
		{
			safe_free(temp);
			safe_free(buffer);
			return (NULL);
		}
		buffer[*readed] = '\0';
		temp = GNL_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	safe_free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	static int	readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readed = 1;
	buffer = ft_read(fd, &readed, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = clean_buffer(buffer);
	if (!line)
	{
		safe_free(buffer);
	}
	return (line);
}
*/
