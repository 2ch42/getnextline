/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:15:19 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/30 19:39:34 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
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

char	*ft_strdup(char *s1, size_t len, size_t *tot_len)
{
	size_t	i;
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
	*tot_len = i;
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, size_t *len1, size_t len2)
{
	char	*ret_str;
	size_t	i;

	ret_str = (char *)malloc(sizeof(char) * (*len1 + len2 + 1));
	if (!ret_str)
		return (ft_clear_str(&s1));
	i = 0;
	while (i < *len1)
	{
		*(ret_str + i) = *(s1 + i);
		i++;
	}
	while (i < len2 + *len1)
	{
		*(ret_str + i) = *(s2 + i - *len1);
		i++;
	}
	*len1 = i;
	*(ret_str + i) = '\0';
	free(s1);
	s1 = NULL;
	return (ret_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len, size_t tot_len)
{
	char		*ret_str;
	size_t		i;
	size_t		real_len;

	i = 0;
	real_len = 0;
	while (real_len + start < tot_len && real_len < len)
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
