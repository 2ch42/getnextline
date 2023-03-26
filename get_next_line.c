/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:56 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/26 18:07:08 by changhyl         ###   ########.fr       */
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

static char	*get_ret_str(char **str, int *idx_addr)
{
	char	*ret_str;

	if (!(*str))
		return (NULL);
	if (**str == '\0')
		return (NULL);
	if (*idx_addr == -1)
		return (*str);
	ret_str = ft_substr(*str, 0, *idx_addr + 1);
	if (!ret_str)
		return (ft_clear_str(str));
	return (ret_str);
}

static char	*get_new_buf(char *str, int *idx_addr)
{
	int		len;
	char	*ret_str;

	if (!str)
		return (NULL);
	if (*str == '\0')
		return (ft_clear_str(&str));
	len = ft_strlen(str);
	if (*idx_addr == -1)
		return (NULL);
	ret_str = ft_substr(str, *idx_addr + 1, len - *idx_addr - 1);
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
	int			idx;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (ft_clear_str(&read_buf));
	while (1)
	{
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		read_result = read(fd, buf, BUFFER_SIZE);
		if (read_result <= 0)
			break ;
		if (!read_buf)
			read_buf = ft_strdup(buf, read_result);
		else
			read_buf = ft_strjoin(read_buf, buf, read_result);
		if (check_nl(buf) != -1)
			break ;
	}
	idx = check_nl(read_buf);
	ret_str = get_ret_str(&read_buf, &idx);
	read_buf = get_new_buf(read_buf, &idx);
	return (ret_str);
}
