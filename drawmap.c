/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:37:27 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/15 11:15:31 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drawwall(t_vars *vars, int i)
{
	int	width;
	int	height;

	vars->wlx[i] = vars->pxx;
	vars->wly[i] = vars->pxy;
	vars->txt = mlx_xpm_file_to_image
		(vars->mlx, "./img/wall.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->txt, vars->pxx, vars->pxy);
	mlx_destroy_image(vars->mlx, vars->txt);
	return (1);
}

int	drawex(t_vars *vars, int e)
{
	int	width;
	int	height;

	vars->exx[e] = vars->pxx;
	vars->exy[e] = vars->pxy;
	vars->txt = mlx_xpm_file_to_image
		(vars->mlx, "./img/exit.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->txt, vars->pxx, vars->pxy);
	mlx_destroy_image(vars->mlx, vars->txt);
	return (1);
}

int	drawcol(t_vars *vars, int c)
{
	int	width;
	int	height;

	vars->colx[c] = vars->pxx;
	vars->coly[c] = vars->pxy;
	vars->txt = mlx_xpm_file_to_image
		(vars->mlx, "./img/col.xpm", &width, &height);
	mlx_put_image_to_window
		(vars->mlx, vars->win, vars->txt, vars->pxx, vars->pxy);
	mlx_destroy_image(vars->mlx, vars->txt);
	return (1);
}

char	*drawmapcont(t_vars *vars, char *s)
{
	if (*s == '\n')
	{
		vars->pxx = 0;
		vars->pxy += 70;
		s++;
	}
	if (*s == 'P')
	{
		vars->x = vars->pxx;
		vars->y = vars->pxy;
	}
	return (s);
}

void	drawmap(t_vars *vars, char *s)
{
	while (*s)
	{
		s = drawmapcont(vars, s);
		if (*s == '1')
		{
			vars->wlen += drawwall(vars, vars->i);
			vars->i++;
		}
		if (*s == 'C')
		{
			vars->clen += drawcol(vars, vars->cnum);
			vars->cnum++;
			vars->c += 1;
		}
		if (*s == 'E')
		{
			vars->exlen += drawex(vars, vars->e);
			vars->e++;
		}
		vars->pxx += 70;
		s++;
	}
	free(vars->map);
}
