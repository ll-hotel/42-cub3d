/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:36:34 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/25 16:26:41 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_H
# define BASICS_H
# include <sys/types.h>

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	ft_bzero(void *s, u_long n);
void	*ft_calloc(u_long nmemb, u_long size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, u_long n);
int		ft_memcmp(const void *s1, const void *s2, u_long n);
void	*ft_memcpy(void *dest, const void *src, u_long n);
void	*ft_memmove(void *dest, const void *src, u_long n);
void	*ft_memset(void *s, int c, u_long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
u_long	ft_strlcpy(char *dst, const char *src, u_long size);
void	ft_striteri(char *s, void (*f)(u_int, char *));
u_long	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(const char *s, char (*f)(u_int, char));
int		ft_strncmp(const char *s1, const char *s2, u_long n);
char	*ft_strnstr(const char *big, const char *little,
			u_long len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, u_int start, \
			u_long len);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_log_b(long n, u_long b);
int		ft_log_ub(u_long n, u_long b);
char	*ft_utoa(u_int n);
char	*ft_xtoa(u_long value, short ox, short capital);

#endif
