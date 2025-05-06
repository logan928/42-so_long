/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:39:59 by uwettasi          #+#    #+#             */
/*   Updated: 2025/03/09 16:28:27 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*free_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

static	char	*r_cont(char **storage, char **chunk, int rc, char **temp)
{
	if (rc >= 0)
		(*chunk)[rc] = '\0';
	if (!*storage)
	{
		*storage = malloc(sizeof(char) + 1);
		if (!*storage)
			return (free_buffer(chunk));
		(*storage)[0] = '\0';
	}
	*temp = ft_strjoin(*storage, *chunk);
	if (!*temp)
	{
		free(*chunk);
		*chunk = NULL;
		return (free_buffer(storage));
	}
	if (*storage)
		free(*storage);
	*storage = *temp;
	if (!*storage)
		return (free_buffer(storage));
	return (*storage);
}

static	char	*read_to_temp_storage(size_t fd, char *storage)
{
	char	*chunk;
	int		read_count;
	char	*temp;

	read_count = 1;
	temp = NULL;
	chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!chunk)
		return (free_buffer(&storage));
	while (read_count > 0)
	{
		read_count = read(fd, chunk, BUFFER_SIZE);
		storage = r_cont(&storage, &chunk, read_count, &temp);
		if (ft_strchr(storage, '\n'))
			break ;
	}
	free (chunk);
	chunk = NULL;
	if (read_count < 0)
		return (free_buffer(&storage));
	return (storage);
}

static	char	*process_buffer(char **storage, size_t length, size_t	index)
{
	char	*next_line;
	char	*temp;

	next_line = NULL;
	temp = NULL;
	if (length > 0)
	{
		next_line = ft_substr(*storage, 0, index + 1);
		if (length >= index +1)
		{
			temp = ft_substr(*storage, index + 1, (length - index - 1));
			if (!temp)
				return (free_buffer(storage));
			if (*storage)
				free(*storage);
			*storage = temp;
		}
	}
	if (!next_line)
		return (free_buffer(storage));
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char		*temp_buffer; 
	char			*has_new_line;
	char			*new_line;
	size_t			index;

	has_new_line = NULL;
	new_line = NULL;
	index = 0;
	if (fd < 0 || read(fd, temp_buffer, 0) < 0)
		return (free_buffer(&temp_buffer));
	if (temp_buffer)
		has_new_line = ft_strchr(temp_buffer, '\n');
	if (!has_new_line)
		temp_buffer = read_to_temp_storage(fd, temp_buffer);
	if (temp_buffer)
	{
		while ((temp_buffer)[index] && (temp_buffer)[index] != '\n')
			index++;
		if ((temp_buffer)[index] == '\0')
			index--;
		new_line = process_buffer(&temp_buffer, ft_strlen(temp_buffer), index);
	}
	return (new_line);
}
