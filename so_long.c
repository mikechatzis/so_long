/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:51:03 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/14 20:16:15 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allblackr(t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = vars->x;
	while (x-- > vars->x - 70)
	{
		y = vars->y;
		while (y++ < vars->y + 69)
			mlx_pixel_put(vars->mlx, vars->win, x, y, 0);
	}
}

void	allblackl(t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = vars->x + 69;
	while (x++ <= vars->x + 140)
	{
		y = vars->y;
		while (y++ < vars->y + 69)
			mlx_pixel_put(vars->mlx, vars->win, x, y, 0);
	}
}

void	allblacku(t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = vars->x;
	while (x++ < vars->x + 69)
	{
		y = vars->y + 69;
		while (y++ < vars->y + 139)
			mlx_pixel_put(vars->mlx, vars->win, x, y, 0);
	}
}

void	allblackd(t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = vars->x;
	while (x++ < vars->x + 69)
	{
		y = vars->y;
		while (y-- > vars->y - 70)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, 0);
			if (y >= vars->y)
				break ;
		}
	}
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->mvs = 0;
	vars->i = 0;
	vars->cnum = 0;
	vars->e = 0;
	vars->pxx = 0;
	vars->pxy = 0;
	argerrors(argc, argv);
	vars->map = evalmap(argv[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->winx, vars->winy, "so_long");
	drawmap(vars, vars->map);
	mlx_hook(vars->win, 17, 0L, key_hook_exit, vars);
	mlx_key_hook(vars->win, key_pressed, vars);
	mlx_loop_hook(vars->mlx, catdraw, vars);
	mlx_loop(vars->mlx);
	return (1);
}
