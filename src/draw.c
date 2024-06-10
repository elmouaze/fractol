/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:46:14 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/10 06:38:35 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static t_point	sum_point(t_point p1, t_point p2)
{
	t_point	res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	return (res);
}

// (x + yi) * (x + yi)
// x^2 + zyi + zyi +y^2i^2
// x^2 + 2xyi - y^2
// (x^2 - y^2) + (2xyi)
// i = x*y*2  && x = (x^2 - y^2)
static t_point	ft_einstein(t_point p)
{
	t_point	res;

	res.x = (p.x * p.x) - (p.y * p.y);
	res.y = p.x * p.y * 2;
	return (res);
}

//z = z^2 + c
static void	mandelbrot(int x, int y, t_fractal *info)
{
	t_point	z;
	t_point	c;
	int		i;

	i = 0;
	z.y = 0.0;
	z.x = 0.0;
	c.x = scale(x, -2 * info->zoom, WIDTH, +2 * info->zoom);
	c.y = scale(y, +2 * info->zoom, HEIGHT, -2 * info->zoom);
	c.x -= 0.5;
	while (i < 100)
	{
		z = sum_point (ft_einstein (z), c);
		if (((z.x * z.x) + (z.y * z.y)) > info->limits)
		{
			my_mlx_pixel_put (&info->img, x, y, 0x75D5FD * i);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put (&info->img, x, y, 0xFF2281);
}

static void	julia(int x, int y, t_fractal *info)
{
	t_point	z;
	t_point	c;
	int		i;

	i = 0;
	c.x = info->x;
	c.y = info->y;
	z.x = scale(x, -2 * info->zoom, WIDTH, +2 * info->zoom);
	z.y = scale(y, +2 * info->zoom, HEIGHT, -2 * info->zoom);
	while (i < 100)
	{
		z = sum_point (ft_einstein (z), c);
		if (((z.x * z.x) + (z.y * z.y)) > info->limits)
		{
			my_mlx_pixel_put(&info->img, x, y, 0x75D5FD * i);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put (&info->img, x, y, 0xFF2281);
}

void	ft_adjust(t_fractal *info)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (info->map == 1)
				julia(x, y, info);
			else if (info->map == 2)
				mandelbrot(x, y, info);
		}
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img.img, 0, 0);
}
