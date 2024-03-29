/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:21:04 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/30 19:54:58 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_clear_str(char **str);
char	*ft_strdup(char *s1, size_t len, size_t *tot_len);
char	*ft_strjoin(char *s1, char *s2, size_t *len1, size_t len2);
char	*ft_substr(char *s, unsigned int start, size_t len, size_t tot_len);
char	*get_next_line(int fd);

#endif
