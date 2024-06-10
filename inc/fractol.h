/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:20:21 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/10 06:36:24 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 900
# define WIDTH 900

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	char	*name;
	t_data	img;
	double	limits;
	int		iteration;
	double	zoom;
	int		map;
	double	x;
	double	y;
}			t_fractal;

typedef struct s_point
{
	double	x;
	double	y;
}		t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_adjust(t_fractal *info);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
double	ascii_to_double(char *s);
int		ft_isdigit(int x);
void	put_err(void);
int		ft_check_arg(int count, char **av, t_fractal *info);
int		close_fractol(t_fractal *f);
double	scale(double point, double new_min, double old_max, double new_max);

#endif
