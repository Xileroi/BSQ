/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:38:29 by yalounic          #+#    #+#             */
/*   Updated: 2023/05/14 09:05:36 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BBQ_H
# define BBQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_cube
{
	int		val;
	int		x;
	int		y;
	int		xtps;
	int		ytps;
	int		nb_line;
	int		nb_col;
	char	empty;
	char	barrier;
	char	square;
	char	**map;
}t_cube;

typedef struct s_cube_tmp
{
	int	val;
	int	x;
	int	y;
	int	xtps;
	int	ytps;
}t_cube_tmp;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		init_map(t_cube *cube, char *src);
int		ft_recup_symb(t_cube *cube, char *str);
void	init_tab(t_cube *cube, char *map_txt);
void	malloc_tab(t_cube *cube, char *map_txt);
void	print_map(t_cube *cube);
int		algo(t_cube *cube, t_cube_tmp *cube_tmp);
int		verif_ligne(t_cube *cube, t_cube_tmp *cube_tmp);
int		verif_col(t_cube *cube, t_cube_tmp *cube_tmp);
int		verif2(t_cube *cube, t_cube_tmp *cube_tmp);
int		verif(t_cube *cube, t_cube_tmp *cube_tmp);
int		call_algo(t_cube *cube);
void	init_cube(t_cube *cube, t_cube_tmp *cube_tmp);
void	change_cube(t_cube *cube, t_cube_tmp *cube_tmp);
void	res_tps(t_cube_tmp *cube_tmp);
int		modif_map(t_cube *cube);
int		good(t_cube *cube);
char	*ft_strcpy(char *dest, char *src);
int		init_map_du_bled(t_cube *cube);
int		ft_verif_file(char *dest);
int		apelle(char *str, t_cube *cube, int save);
int		ft_check_first(char *str, t_cube *cube, int save);

#endif