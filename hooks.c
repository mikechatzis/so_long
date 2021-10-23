/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:44:03 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/15 13:29:03 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	free(vars);
	exit(0);
}

void	linuxhooks(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 0xff1b || keycode == 122)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		free(vars);
		exit(0);
	}
	if (!vars->c && done(vars))
		return ;
	if (vars->x < vars->winx && vars->y < vars->winy)
	{
		if (keycode == 0x0064 || keycode == 0xff53)
			catwalk(vars);
		if (keycode == 0x0073 || keycode == 0xff54)
			catwalkd(vars);
		if (keycode == 0x0061 || keycode == 0xff51)
			catwalkb(vars);
		if (keycode == 0x0077 || keycode == 0xff52)
			catwalkup(vars);
	}
}

void	machooks(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		free(vars);
		exit(0);
	}
	if (!vars->c && done(vars))
		return ;
	if (keycode == 2 || keycode == 124)
		catwalk(vars);
	if (keycode == 1 || keycode == 125)
		catwalkd(vars);
	if (keycode == 0 || keycode == 123)
		catwalkb(vars);
	if (keycode == 13 || keycode == 126)
		catwalkup(vars);
}

int	key_pressed(int keycode, t_vars *vars, struct utsname *sys)
{
	uname(sys);
	if (!ft_strncmp(sys->sysname, "Darwin", 6))
		machooks(keycode, vars);
	else if (!ft_strncmp(sys->sysname, "Linux", 5))
		linuxhooks(keycode, vars);
	return (0);
}
