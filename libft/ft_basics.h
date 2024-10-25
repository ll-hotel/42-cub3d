/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:36:34 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/10/18 14:27:02 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASICS_H
# define FT_BASICS_H

int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
void			ft_bzero(void *s, unsigned long n);
void			*ft_calloc(unsigned long nmemb, unsigned long size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, unsigned long n);
int				ft_memcmp(const void *s1, const void *s2, unsigned long n);
void			*ft_memcpy(void *dest, const void *src, unsigned long n);
void			*ft_memmove(void *dest, const void *src, unsigned long n);
void			*ft_memset(void *s, int c, unsigned long n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
char			**ft_split(const char *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long size);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
unsigned long	ft_strlen(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, unsigned long n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *big, const char *little,
					unsigned long len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_substr(const char *s, unsigned int start, \
		unsigned long len);
int				ft_tolower(int c);
int				ft_toupper(int c);

char			*ft_utoa(unsigned int n);
char			*ft_xtoa(unsigned long value, short ox, short capital);
long			ft_limit(long value, long lower_bound, long upper_bound);
long			ft_abs(long n);
double			ft_absf(double n);
long			ft_max(long a, long b);
double			ft_maxf(double a, double b);
long			ft_min(long a, long b);
double			ft_minf(double a, double b);
#endif
