/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:37:27 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/15 11:00:59 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	col_r(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->wlen)
	{
		if ((vars->x + 70 == vars->wlx[i]) && (vars->y == vars->wly[i]))
			return (1);
	}
	return (0);
}

int	col_l(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->wlen)
	{
		if ((vars->x - 70 == vars->wlx[i]) && (vars->y == vars->wly[i]))
			return (1);
	}
	return (0);
}

int	col_up(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->wlen)
	{
		if ((vars->x == vars->wlx[i]) && (vars->y - 70 == vars->wly[i]))
			return (1);
	}
	return (0);
}

int	col_d(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->wlen)
	{
		if ((vars->x == vars->wlx[i]) && (vars->y + 70 == vars->wly[i]))
			return (1);
	}
	return (0);
}

int	end(t_vars *vars)
{
	int	width;
	int	height;

	if (!vars->c && done(vars))
	{
		vars->txt = mlx_xpm_file_to_image
			(vars->mlx, "./img/win.xpm", &width, &height);
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->txt, vars->winx / 2 - 109,
				vars->winy / 2 - 53);
		mlx_destroy_image(vars->mlx, vars->txt);
	}
	return (0);
}
