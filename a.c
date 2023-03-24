/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:56 by changhyl          #+#    #+#             */
/*   Updated: 2023/01/03 21:40:12 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (*(str + i))
	{
		if (*(str + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_clear_str(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

static void	get_ret_str(char **buf_addr, char **ret_addr)
{
	int		idx;
	int		len;

	if (!(*buf_addr))
	{
		*ret_addr = NULL;
		return ;
	}
	else if (**buf_addr == '\0')
	{
		*ret_addr = ft_clear_str(buf_addr);
		return ;
	}
	idx = check_nl(*buf_addr);
	len = ft_strlen(*buf_addr);
	if (idx == -1)
	{
		*ret_addr = *buf_addr;
		if (len != 0)
			*buf_addr = NULL;
		return ;
	}
	*ret_addr = ft_substr(*buf_addr, 0, idx + 1);
	if (!(*ret_addr))
		ft_clear_str(buf_addr);
	*buf_addr = ft_substr(*buf_addr, idx + 1, len - idx - 1);
	if (!(*buf_addr))
		ft_clear_str(buf_addr);
	return ;
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*ret_str;
	static char	*read_buf;
	int			read_result;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (ft_clear_str(&read_buf));
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
	get_ret_str(&read_buf, &ret_str);
	return (ret_str);
}
