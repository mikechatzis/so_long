/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:54:57 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/15 12:01:20 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_nstrlen(const char *c)
{
	size_t	len;

	len = 0;
	while (*c && *c != '\n')
	{
		c++;
		len++;
	}
	return (len);
}

static size_t	errout3(size_t i, size_t j, char *s, t_vars *vars)
{
	while (s[--i] != '\n')
	{
		if (s[i] != '1')
		{
			write(2, "Error\nMap is not surounded by walls\n", 36);
			free(s);
			free(vars);
			exit(0);
		}
	}
	i = ft_nstrlen(s);
	j = i;
	while (s[j])
	{
		if (i != ft_nstrlen(&s[j + 1]))
		{
			write(2, "Error\nMap is not rectangular\n", 29);
			free(s);
			free(vars);
			exit(0);
		}
		j += i + 1;
	}
	i = -1;
	return (i);
}

static void	errout4(size_t i, char *s, t_vars *vars)
{
	while (s[++i])
	{
		if (s[i] != 'P' && s[i] != 'E' && s[i] != 'C'
			&& s[i] != '1' && s[i] != '0' && s[i] != '\n')
		{
			write(2, "Error\nInvalid map element\n", 26);
			free(s);
			free(vars);
			exit(0);
		}
	}
}

static size_t	errout2(size_t i, char *s, t_vars *vars)
{
	while (s[i])
	{
		if (s[i] == 'P' && vars->p)
		{
			write(2, "Error\nToo many starting positions\n", 34);
			free(s);
			free(vars);
			exit(0);
		}
		if (s[i] == 'P')
			vars->p = 1;
		if (s[i] == '\n')
		{
			if (s[i - 1] != '1' || s[i + 1] != '1')
			{
				write(2, "Error\nMap is not surounded by walls\n", 36);
				free(s);
				free(vars);
				exit(0);
			}
		}
		i++;
	}
	return (i);
}

void	check(char	*s, t_vars *vars)
{
	size_t	i;

	i = -1;
	vars->p = 0;
	while (s[++i] != '\n')
	{
		if (s[i] != '1')
		{
			write(2, "Error\nMap is not surounded by walls\n", 36);
			free(s);
			free(vars);
			exit(0);
		}
	}	
	i = errout2(i, s, vars);
	i = errout3(i, 0, s, vars);
	errout4(i, s, vars);
}
