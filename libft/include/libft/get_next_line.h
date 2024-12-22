/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:44:04 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/25 13:26:50 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE <= 0
#   undef BUFFER_SIZE
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

char	*get_next_line(int fd);

#endif
