/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:37:27 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/14 19:56:04 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	food_r(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->clen)
	{
		if ((vars->x + 70 == vars->colx[i]) && (vars->y == vars->coly[i]))
		{
			vars->colx[i] = 0;
			vars->coly[i] = 0;
			return (1);
		}
	}
	return (0);
}

int	food_l(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->clen)
	{
		if ((vars->x - 70 == vars->colx[i]) && (vars->y == vars->coly[i]))
		{
			vars->colx[i] = 0;
			vars->coly[i] = 0;
			return (1);
		}
	}
	return (0);
}

int	food_up(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->clen)
	{
		if ((vars->x == vars->colx[i]) && (vars->y - 70 == vars->coly[i]))
		{
			vars->colx[i] = 0;
			vars->coly[i] = 0;
			return (1);
		}
	}
	return (0);
}

int	food_d(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->clen)
	{
		if ((vars->x == vars->colx[i]) && (vars->y + 70 == vars->coly[i]))
		{
			vars->colx[i] = 0;
			vars->coly[i] = 0;
			return (1);
		}
	}
	return (0);
}
