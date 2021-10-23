/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:37:27 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/15 10:50:17 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	renderexit_r(t_vars *vars)
{
	int	width;
	int	height;

	vars->txt = mlx_xpm_file_to_image
		(vars->mlx, "./img/exit.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->txt, vars->x - 70, vars->y);
}

void	renderexit_d(t_vars *vars)
{
	int	width;
	int	height;

	vars->txt = mlx_xpm_file_to_image
		(vars->mlx, "./img/exit.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->txt, vars->x, vars->y - 70);
}

void	renderexit_l(t_vars *vars)
{
	int	width;
	int	height;

	vars->txt = mlx_xpm_file_to_image
		(vars->mlx, "./img/exit.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->txt, vars->x + 70, vars->y);
}

void	renderexit_up(t_vars *vars)
{
	int	width;
	int	height;

	vars->txt = mlx_xpm_file_to_image
		(vars->mlx, "./img/exit.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->txt, vars->x, vars->y + 70);
}
