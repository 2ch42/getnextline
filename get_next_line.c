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

static char	*get_ret_str(char **str)
{
	char	*ret_str;

	if (!(*str))
		return (NULL);
	if (**str == '\0')
		return (NULL);
	if (check_nl(*str) == -1)
		return (*str);
	ret_str = ft_substr(*str, 0, check_nl(*str) + 1);
	if (!ret_str)
		return (ft_clear_str(str));
	return (ret_str);
}

static char	*get_new_buf(char *str)
{
	int		idx;
	char	*ret_str;

	if (!str)
		return (NULL);
	if (*str == '\0')
		return (ft_clear_str(&str));
	idx = check_nl(str);
	if (check_nl(str) == -1 && ft_strlen(str) != 0)
		return (NULL);
	if (check_nl(str) == -1)
		return (ft_clear_str(&str));
	ret_str = ft_substr(str, idx + 1, ft_strlen(str) - idx - 1);
	free(str);
	str = NULL;
	return (ret_str);
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
	ret_str = get_ret_str(&read_buf);
	read_buf = get_new_buf(read_buf);
	return (ret_str);
}
