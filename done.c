/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:37:27 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/14 19:56:47 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	done(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->exlen)
	{
		if ((vars->x == vars->exx[i]) && (vars->y == vars->exy[i]))
			return (1);
	}
	return (0);
}

int	doner(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->exlen)
	{
		if ((vars->x - 70 == vars->exx[i]) && (vars->y == vars->exy[i]))
			return (1);
	}
	return (0);
}

int	donel(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->exlen)
	{
		if ((vars->x + 70 == vars->exx[i]) && (vars->y == vars->exy[i]))
			return (1);
	}
	return (0);
}

int	doneup(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->exlen)
	{
		if ((vars->x == vars->exx[i]) && (vars->y + 70 == vars->exy[i]))
			return (1);
	}
	return (0);
}

int	doned(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (++i <= vars->exlen)
	{
		if ((vars->x == vars->exx[i]) && (vars->y - 70 == vars->exy[i]))
			return (1);
	}
	return (0);
}
