/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:07 by almatos           #+#    #+#             */
/*   Updated: 2022/12/08 11:53:49 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(long fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	long		size_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = next_line(buffer, 0);
	if (clean(buffer))
		return (line);
	size_read = 1;
	while (size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1 || (size_read == 0 && line[0] == '\0'))
		{
			free(line);
			return (NULL);
		}
		line = next_line(buffer, line);
		if (clean(buffer))
			break ;
	}
	return (line);
}
