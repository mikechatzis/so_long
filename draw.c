/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:37:27 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/15 11:02:45 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	catdraw(t_vars *vars)
{
	int		height;
	int		width;

	end(vars);
	if (!vars->c && done(vars))
		return (0);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/still1.xpm", &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->cat, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(10000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/still2.xpm", &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->cat, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(150000);
	catdrawx(vars, width, height);
	return (0);
}

int	catwalk(t_vars *vars)
{
	int		height;
	int		width;

	if (col_r(vars))
		return (0);
	if (food_r(vars))
		vars->c -= 1;
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walk1.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x += 17, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walk2.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x += 18, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	catwalkx(vars, width, height);
	return (0);
}

int	catwalkd(t_vars *vars)
{
	int		height;
	int		width;

	if (col_d(vars))
		return (0);
	if (food_d(vars))
		vars->c -= 1;
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walk1.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y += 17);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walk2.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y += 18);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	catwalkdx(vars, width, height);
	return (0);
}

int	catwalkup(t_vars *vars)
{
	int		height;
	int		width;

	if (col_up(vars))
		return (0);
	if (food_up(vars))
		vars->c -= 1;
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walkb1.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y -= 17);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walkb2.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y -= 18);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	catwalkupx(vars, width, height);
	return (0);
}

int	catwalkb(t_vars *vars)
{
	int		height;
	int		width;

	if (col_l(vars))
		return (0);
	if (food_l(vars))
		vars->c -= 1;
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walkb1.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x -= 17, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walkb2.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x -= 18, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	catwalkbx(vars, width, height);
	return (0);
}
