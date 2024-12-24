/* ***************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_img.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:00:09 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/12/24 12:00:51 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ***************************************************************************/

#ifndef S_IMG_H
# define S_IMG_H

typedef struct s_img
{
	void	*mlx_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		pixels;
}	t_img;

int		s_img_init(t_img *img, void *mlx_ptr, int width, int height);
void	s_img_destroy(t_img *img);
void	s_img_put_pixel(t_img *img, int x, int y, int pixel);
int		s_img_get_pixel(const t_img *img, int x, int y);
void	s_img_put_t_img(t_img *dst, const t_img *src, int x, int y);

#endif /* ifndef S_IMG_H */
