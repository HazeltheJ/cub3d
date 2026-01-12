/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:01:36 by ajami             #+#    #+#             */
/*   Updated: 2025/01/18 18:02:32 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char *big_buffer)
{
	free(big_buffer);
	return (NULL);
}

static char	*read_file(int fd, char *big_buffer)
{
	char	*buffer;
	int		len_read;
	char	*temp;

	if (!big_buffer)
		big_buffer = ft_strdup("");
	if (!big_buffer)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(big_buffer));
	len_read = 1;
	while (!ft_strchr(big_buffer, '\n') && len_read > 0 && big_buffer)
	{
		len_read = read(fd, buffer, BUFFER_SIZE);
		buffer[len_read] = '\0';
		temp = big_buffer;
		big_buffer = ft_strjoin(big_buffer, buffer);
		free(temp);
	}
	free(buffer);
	if (len_read < 0 || !big_buffer)
		return (0);
	return (big_buffer);
}

static char	*ft_line(char *big_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!big_buffer)
		return (0);
	while (big_buffer[i] != '\n' && big_buffer[i] != '\0')
		i++;
	line = malloc((i + 1 + (big_buffer[i] == '\n')) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (big_buffer[i] != '\n' && big_buffer[i] != '\0')
	{
		line[i] = big_buffer[i];
		i++;
	}
	if (big_buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_update(char *big_buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (big_buffer[i] != '\n' && big_buffer[i] != '\0')
		i++;
	if (!big_buffer[i])
	{
		free(big_buffer);
		return (0);
	}
	i++;
	temp = malloc((ft_strlen(big_buffer) - i + 1) * sizeof(char));
	if (!temp)
	{
		big_buffer = ft_free(big_buffer);
		return (0);
	}
	j = 0;
	while (big_buffer[i])
		temp[j++] = big_buffer[i++];
	temp[j] = '\0';
	free(big_buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*big_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (big_buffer)
			big_buffer = ft_free(big_buffer);
		return (0);
	}
	big_buffer = read_file(fd, big_buffer);
	if (!big_buffer)
	{
		big_buffer = ft_free(big_buffer);
		return (0);
	}
	line = ft_line(big_buffer);
	if (!line || line[0] == '\0')
	{
		free(line);
		big_buffer = ft_free(big_buffer);
		return (0);
	}
	big_buffer = ft_update(big_buffer);
	return (line);
}
