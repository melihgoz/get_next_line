/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megoz <megoz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:50:00 by megoz             #+#    #+#             */
/*   Updated: 2025/10/22 10:50:00 by megoz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*
** Simple test program for get_next_line
** Compile: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
** Usage: ./a.out [filename]
*/
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_count;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open file\n");
		return (1);
	}
	line_count = 1;
	while ((line = get_next_line(fd)))
	{
		printf("Line %d: %s", line_count, line);
		free(line);
		line_count++;
	}
	close(fd);
	return (0);
}
