/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megoz <megoz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:26:52 by megoz             #+#    #+#             */
/*   Updated: 2025/10/22 10:50:00 by megoz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Helper function to join two strings
** Frees s1 after joining
*/
static char	*join_and_free(char *s1, char *s2, int s2_len)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (s1 && s1[i])
		i++;
	result = malloc(i + s2_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

/*
** Main function that reads from fd and returns one line at a time
** Uses read() from <unistd.h> to read BUFFER_SIZE bytes at a time
** Returns NULL when EOF or error
*/
char	*get_next_line(int fd)
{
	static char	*storage;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		i = find_newline(storage);
		if (i >= 0)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(storage), storage = NULL, NULL);
		buffer[bytes_read] = '\0';
		storage = join_and_free(storage, buffer, bytes_read);
		if (!storage)
			return (NULL);
	}
	if (!storage || !storage[0])
		return (free(storage), storage = NULL, NULL);
	i = find_newline(storage);
	if (i < 0)
	{
		i = 0;
		while (storage[i])
			i++;
	}
	else
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	j = 0;
	while (j < i)
	{
		line[j] = storage[j];
		j++;
	}
	line[j] = '\0';
	buffer[0] = '\0';
	j = 0;
	while (storage[i])
		buffer[j++] = storage[i++];
	buffer[j] = '\0';
	free(storage);
	storage = NULL;
	if (buffer[0])
	{
		storage = malloc(j + 1);
		if (storage)
		{
			i = 0;
			while (i < j)
			{
				storage[i] = buffer[i];
				i++;
			}
			storage[i] = '\0';
		}
	}
	return (line);
}
