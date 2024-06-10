/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 02:46:12 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/10 06:38:22 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (tmp1[i] || tmp2[i])
	{
		if (tmp1[i] != tmp2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (fd < 0 || !s)
		return ;
	while (s[index] != '\0')
	{
		write (fd, &s[index], 1);
		index++;
	}
}

void	put_err(void)
{
	ft_putstr_fd ("error in arguments", 1);
	exit (EXIT_FAILURE);
}

static int	ft_atoi(char **s, int *sign)
{
	int	integer;

	integer = 0;
	while ((**s >= 9 && **s <= 13) || **s == 32)
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1;
		(*s)++;
	}
	while (**s >= '0' && **s <= '9')
	{
		integer = integer * 10 + (**s - '0');
		(*s)++;
	}
	return (integer);
}

double	ascii_to_double(char *s)
{
	int		integer;
	double	power;
	double	dbl;
	int		sign;

	sign = 1;
	(1) && (dbl = 0, power = 1);
	integer = ft_atoi(&s, &sign);
	if (*s == '.')
		s++;
	if (*(s - 1) == '.' && (!*s || *s == ' '))
		put_err();
	while (*s >= '0' && *s <= '9')
	{
		power /= 10;
		dbl = dbl + (*s - '0') * power;
		s++;
	}
	while (*s && *s == ' ')
		s++;
	if (*s != ' ' && *s)
		put_err();
	return ((integer + dbl) * sign);
}
