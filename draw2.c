/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:37:27 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/15 10:49:29 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	catdrawx(t_vars *vars, int width, int height)
{
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/still3.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(150000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/still4.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
}

void	catwalkx(t_vars *vars, int width, int height)
{
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walk3.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x += 17, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walk4.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x += 18, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	vars->mvs += 1;
	printf("moves: %ld\n", vars->mvs);
	if (doner(vars) && vars->c)
		renderexit_r(vars);
	else
		allblackr(vars);
}

void	catwalkdx(t_vars *vars, int width, int height)
{
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walk3.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y += 17);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walk4.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y += 18);
	mlx_destroy_image(vars->mlx, vars->cat);
	vars->mvs += 1;
	printf("moves: %ld\n", vars->mvs);
	if (doned(vars) && vars->c)
		renderexit_d(vars);
	else
		allblackd(vars);
}

void	catwalkupx(t_vars *vars, int width, int height)
{
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walkb3.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y -= 17);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walkb4.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x, vars->y -= 18);
	mlx_destroy_image(vars->mlx, vars->cat);
	vars->mvs += 1;
	printf("moves: %ld\n", vars->mvs);
	if (doneup(vars) && vars->c)
		renderexit_up(vars);
	else
		allblacku(vars);
}

void	catwalkbx(t_vars *vars, int width, int height)
{
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walkb3.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x -= 17, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	usleep(100000);
	vars->cat = mlx_xpm_file_to_image
		(vars->mlx, "./img/walkb4.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->cat, vars->x -= 18, vars->y);
	mlx_destroy_image(vars->mlx, vars->cat);
	vars->mvs += 1;
	printf("moves: %ld\n", vars->mvs);
	if (donel(vars) && vars->c)
		renderexit_l(vars);
	else
		allblackl(vars);
}
