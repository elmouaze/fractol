/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 02:30:28 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/10 06:34:21 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	scale(double point, double new_min, double old_max, double new_max)
{
	return (((new_max - new_min) * (point)) / old_max + new_min);
}

int	close_fractol(t_fractal *f)
{
	if (f->img. img)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->mlx_win)
		mlx_destroy_window(f->mlx, f->mlx_win);
	exit (0);
	return (1);
}

static int	check_arg(char *str)
{
	while (*str && *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			put_err();
		str++;
		if (*str == '.' || *str == ' ')
			return (-1);
	}
	return (-1);
}

int	ft_check_arg(int count, char **av, t_fractal *info)
{
	if (count < 2)
		return (-1);
	else if (ft_strcmp(av[1], "Julia") == 0 && count == 4)
	{
		(1) && (check_arg(av[2]), check_arg(av[3]));
		info->map = 1;
		return (1);
	}
	else if (ft_strcmp(av[1], "Mandelbrot") == 0 && count == 2)
	{
		info->map = 2;
		return (2);
	}
	return (-1);
}
