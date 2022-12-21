/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:56 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/21 23:03:02 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
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

	if (!str)
	{
		free(str);
		return (NULL);
	}
	idx = check_nl(str);
	if (idx == -1)
	{
		str = NULL;
		free(str);
		return (NULL);
	}
	ret_str = ft_substr(str, idx + 1, ft_strlen(str) - idx - 1);
	str = NULL;
	free(str);
	return (ret_str);
}

static char	*get_ret_str(char *str)
{
	char	*ret_str;

	if (!str)
	{
		free(str);
		return (NULL);
	}
	if (check_nl(str) == -1)
	{
		ret_str = ft_strdup(str);
		str = NULL;
		free(str);
		return (ret_str);
	}
	ret_str = ft_substr(str, 0, check_nl(str) - 1);
	free (str);
	return (ret_str);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*read_buf;
	int			read_result;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buf = get_new_str(read_buf);
	while (1)
	{
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		read_result = read(fd, buf, BUFFER_SIZE);
		if (read_result <= 0)
			break ;
		if (!read_buf)
			read_buf = ft_strdup(buf);
		else
			read_buf = ft_strjoin(read_buf, buf);
		if (check_nl(read_buf) != -1)
			break ;
	}
	return (get_ret_str(read_buf));
}
