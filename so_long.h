/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:51:18 by mchatzip          #+#    #+#             */
/*   Updated: 2021/10/15 10:50:08 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "mlxl/mlx.h"
# include "libft/libft.h"
# include <sys/utsname.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*cat;
	char	*map;
	size_t	mvs;
	size_t	x;
	size_t	y;
	int		p;
	int		c;
	int		i;
	int		cnum;
	int		e;
	size_t	winx;
	size_t	winy;
	size_t	pxx;
	size_t	pxy;
	size_t	wlen;
	size_t	clen;
	size_t	exlen;
	size_t	wlx[10000];
	size_t	wly[10000];
	size_t	colx[10000];
	size_t	coly[10000];
	size_t	exx[10000];
	size_t	exy[10000];
	void	*txt;
}				t_vars;

int		key_hook_exit(t_vars *vars);
int		key_pressed(int keycode, t_vars *vars, struct utsname *sys);
int		catdraw(t_vars *vars);
int		catwalk(t_vars *vars);
int		catwalkd(t_vars *vars);
int		catwalkup(t_vars *vars);
int		catwalkb(t_vars *vars);
int		esc_pressed(int keycode, t_vars *vars, struct utsname *sys);
void	linuxhooks(int keycode, t_vars *vars);
void	machooks(int keycode, t_vars *vars);
void	allblackr(t_vars *vars);
void	allblackl(t_vars *vars);
void	allblacku(t_vars *vars);
void	allblackd(t_vars *vars);
char	*get_next_line(int fd);
void	argerrors(int argc, char **argv);
char	*evalmap(char *s, t_vars *vars);
void	check(char	*s, t_vars *vars);
size_t	ft_nstrlen(const char *c);
void	catwalkx(t_vars *vars, int width, int height);
void	catwalkdx(t_vars *vars, int width, int height);
void	catwalkupx(t_vars *vars, int width, int height);
void	catwalkbx(t_vars *vars, int width, int height);
void	drawmap(t_vars *vars, char *s);
int		col_r(t_vars *vars);
int		col_l(t_vars *vars);
int		col_up(t_vars *vars);
int		col_d(t_vars *vars);
int		food_r(t_vars *vars);
int		food_l(t_vars *vars);
int		food_up(t_vars *vars);
int		food_d(t_vars *vars);
int		end(t_vars *vars);
int		done(t_vars *vars);
void	renderexit_r(t_vars *vars);
void	renderexit_l(t_vars *vars);
void	renderexit_up(t_vars *vars);
void	renderexit_d(t_vars *vars);
int		doner(t_vars *vars);
int		donel(t_vars *vars);
int		doneup(t_vars *vars);
int		doned(t_vars *vars);
void	catdrawx(t_vars *vars, int width, int height);

#endif
