/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:56 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/21 19:10:07 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"

static int	check_nl(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_new_str(char *str)
{
	int		idx;
	char	*ret_str;

	if (str == NULL)
		return (NULL);
	idx = check_nl(str);
	if (idx == -1)
		return (NULL);
	return (ft_substr(str, idx + 1, ft_strlen(str) - idx - 1));
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*read_buf;
	int			read_result;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buf = get_new_str(read_buf);
	if (!read_buf)
		free(read_buf);
	while (1)
	{
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		read_result = read(fd, buf, BUFFER_SIZE);
		if (read_result <= 0)
			break ;
		buf[BUFFER_SIZE] = '\0';
		read_buf = ft_strjoin(read_buf, buf);
		if (check_nl(read_buf) != -1)
			break ;
	}
	return (read_buf);
}

//ssize_t read(int fd, void *buf, size_t nbyte);


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
/*
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
/*
int main()
{
	int fd = open("./practice.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s", s);
}
*/
