/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:15:19 by changhyl          #+#    #+#             */
/*   Updated: 2022/12/07 22:19:22 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		write(fd, s + i, 1);
		i++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*(str + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

size_t	ft_strlen(const	char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		*(ret_str + i) = *(s1 + i);
		i++;
	}
	while (j < s2_len)
	{
		*(ret_str + s1_len + j) = *(s2 + j);
		j++;
	}
	*(ret_str + s1_len + s2_len) = '\0';
	return (ret_str);
}
