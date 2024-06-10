/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:21 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/10 06:39:36 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	mouse_hook(int key, int x, int y, t_fractal *info)
{
	x = y;
	if (key == 5)
		info->zoom *= 1.1;
	else if (key == 4)
		info->zoom /= 1.1;
	ft_adjust(info);
	return (1);
}

static int	key_event(int keycode, t_fractal *mlx)
{
	if (keycode == 53)
		close_fractol(mlx);
	return (1);
}

// #define mlx_init(x)  NULL
// protect mlx init() 
static void	ft_init(t_fractal *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		exit(1);
	info->mlx_win = mlx_new_window(info->mlx, WIDTH, HEIGHT, info->name);
	if (!info->mlx)
		close_fractol(info);
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img.img)
		close_fractol(info);
	info->img.addr = mlx_get_data_addr (info->img.img,
			&info->img.bits_per_pixel,
			&info->img.line_length, &info->img.endian);
	mlx_mouse_hook (info->mlx_win, mouse_hook, info);
	mlx_key_hook (info->mlx_win, key_event, info);
	mlx_hook (info->mlx_win, 17, 0, close_fractol, info);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	int			map;

	map = ft_check_arg(ac, av, &fractal);
	if (map == 1)
	{
		fractal.name = "Julia";
		fractal.x = ascii_to_double(av[2]);
		fractal.y = ascii_to_double(av[3]);
	}
	else if (map == 2)
		fractal.name = "Mandelbrot";
	else
		return (ft_putstr_fd ("error in arguments", 1), 1);
	fractal.limits = 4;
	fractal.iteration = 100;
	fractal.zoom = 1;
	ft_init (&fractal);
	ft_adjust (&fractal);
	mlx_loop (fractal.mlx);
}
