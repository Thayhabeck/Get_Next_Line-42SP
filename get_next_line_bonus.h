/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:09:02 by thabeck-          #+#    #+#             */
/*   Updated: 2022/05/13 00:11:18 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
char	*ft_set_accumulator(int fd, char *accumulator);
char	*ft_get_line(char *accumulator);
char	*ft_new_accumulator(char *accumulator);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);

#endif
