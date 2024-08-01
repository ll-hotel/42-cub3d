/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:36:34 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/07/26 13:04:39 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "include/basics.h"
# include "include/ft_printf.h"
# include "include/ft_dprintf.h"
# include "include/lst.h"
# include "include/get_next_line.h"
# include "include/vector.h"

void	*ft_realloc(void *p, unsigned long old_size, unsigned long n);

typedef struct s_fptr	t_fptr;
struct	s_fptr
{
	char	*ptr;
	u_long	size;
};

/* Malloc a new `t_fptr` struct and initialize its inner pointer using `size`.
 * If `size` is null, then `ptr` will be too. */
t_fptr	*fptr_new(u_long size);
/* Initialize a `t_fptr` struct and allocate its inner pointer using `size`. */
void	*fptr_init(t_fptr *fptr, u_long size);
void	fptr_free(t_fptr *fptr, void (*free)(void *));

typedef struct s_sptr	t_sptr;
struct	s_sptr
{
	void	*ptr;
	u_long	refs;
};

t_sptr	*sptr_cpy(t_sptr *sptr);
void	sptr_free(t_sptr *sptr, void (*__free)(void *));

char	maxc(char a, char b);
short	maxs(short a, short b);
int		maxi(int a, int b);
long	maxl(long a, long b);
u_char	maxuc(u_char a, u_char b);
u_short	maxus(u_short a, u_short b);
u_int	maxui(u_int a, u_int b);
u_long	maxul(u_long a, u_long b);
void	*maxp(void *a, void *b);
float	maxf(float a, float b);
double	maxd(double a, double b);

#endif
