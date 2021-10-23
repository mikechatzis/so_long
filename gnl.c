/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:05:16 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/11 14:05:16 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars -> line_length
			+ x * (vars -> bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}*/

void	argerrors(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments.\n", 35);
		exit(0);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		write(2, "Error\nInvalid map.\n", 19);
		exit(0);
	}
}

static int	countrows(char *s)
{
	size_t	i;

	i = 1;
	while (*s)
	{
		if (*s == '\n')
			i++;
		s++;
	}
	return (i);
}

static	void	freed(char *b, t_vars *vars)
{
	free(b);
	free(vars);
	exit(0);
}

static void	errout(int ret, char *b, t_vars *vars)
{
	if (ret == -1)
	{
		write(2, "Error\nfailed to read map\n", 25);
		freed(b, vars);
	}
	if (!ft_strchr(b, 'P'))
	{
		write(2, "Error\nNo player starting position found in map\n", 47);
		freed(b, vars);
	}
	if (!ft_strchr(b, 'E'))
	{
		write(2, "Error\nNo exit found in map\n", 27);
		freed(b, vars);
	}
	if (!ft_strchr(b, 'C'))
	{
		write(2, "Error\nNo collectibles found in map\n", 35);
		freed(b, vars);
	}
}

char	*evalmap(char *s, t_vars *vars)
{
	int		fd;
	char	*path;
	char	*b;
	int		ret;

	b = malloc(10000);
	path = ft_strjoin("./maps/", s);
	fd = open(path, O_CREAT);
	free(path);
	ret = read(fd, b, 10000);
	b[9999] = 0;
	close(fd);
	errout(ret, b, vars);
	check(b, vars);
	vars->winy = countrows(b) * 70;
	vars->winx = (int)ft_nstrlen(b) * 70;
	return (b);
}
