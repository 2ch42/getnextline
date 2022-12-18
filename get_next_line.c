/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:56 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/07 22:19:51 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*buf_tmp;
	static char	*read_buf;
	int		read_result;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	read_result = 1;
	while (read_result > 0)
	{
		read_result = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		buf_tmp = strdup(buf);
	}
}

//ssize_t read(int fd, void *buf, size_t nbyte);

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	char buf [11];
	int fd = open("./practice.txt", O_RDONLY);
	int i = 0;
	while (1)
	{
		memset(buf, 0, 11);
		int result = read(fd, buf, 10);
		if (result <= 0) break;
		printf("%d\n", result);
		i++;
	}
	return (0);
}
*/
