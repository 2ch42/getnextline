/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:15:19 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/26 15:54:22 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *s1, int len)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, int s2_len)
{
	char	*ret_str;
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	ret_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret_str)
		return (ft_clear_str(&s1));
	i = 0;
	while (i < s1_len)
	{
		*(ret_str + i) = *(s1 + i);
		i++;
	}
	while (i < s2_len + s1_len)
	{
		*(ret_str + i) = *(s2 + i - s1_len);
		i++;
	}
	*(ret_str + i) = '\0';
	free(s1);
	s1 = NULL;
	return (ret_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*ret_str;
	size_t		i;
	size_t		real_len;

	i = 0;
	real_len = 0;
	while (real_len + start < ft_strlen(s) && real_len < len)
		real_len++;
	ret_str = (char *)malloc(sizeof(char) * (real_len + 1));
	if (!ret_str)
		return (NULL);
	while (i < real_len)
	{
		*(ret_str + i) = *(s + start + i);
		i++;
	}
	*(ret_str + i) = '\0';
	return (ret_str);
}
