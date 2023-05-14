/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:15:49 by yalounic          #+#    #+#             */
/*   Updated: 2023/05/14 09:04:56 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bbq.h"

void	malloc_tab(t_cube *cube, char *map_txt)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	cube->map = (char **)malloc((sizeof(char *) * cube->nb_line) + 1);
	while (map_txt[j] != '\n')
		j++;
	j++;
	while (i < cube->nb_line)
	{
		while (map_txt[j] != '\n' && map_txt[j] != '\0')
		{
			k++;
			j++;
		}
		cube->map[i] = (char *)malloc((sizeof(char) * (k + 1)) + 1);
		if (map_txt[j] != '\0' && map_txt[j] == '\n')
			j++;
		k = 0;
		i++;
	}
}

char	*ft_strncat_m(char *dest, char *src, int taille)
{
	int			i;
	int			tdest;
	char		*ret;

	ret = malloc((sizeof(char) * (ft_strlen(dest) + taille)) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (dest[++i])
		ret[i] = dest[i];
	ret[i] = 0;
	tdest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < taille)
	{		
		ret[tdest + i] = src[i];
		i++;
	}
	ret[tdest + i] = '\0';
	free(dest);
	return (ret);
}

int	i_need_lines(t_cube *cube, char *dest)
{
	cube->nb_line = 0;
	if (ft_recup_symb(cube, dest) == 1)
	{
		init_tab(cube, dest);
		free(dest);
		return (1);
	}
	free(dest);
	return (0);
}

int	init_map(t_cube *cube, char *src)
{
	char	*buf;
	int		taille;
	char	*dest;
	int		map_file;

	taille = 1;
	buf = malloc(sizeof(char) * 4097);
	map_file = open(src, O_RDONLY);
	dest = malloc((sizeof(char) * 1) + 1);
	if (!dest)
		return (0);
	dest[0] = 0;
	while (taille > 0)
	{
		taille = read(map_file, buf, 4096);
		if (taille > 0)
		{
			buf[taille] = '\0';
			dest = ft_strncat_m(dest, buf, taille);
		}
	}
	free(buf);
	if (dest[0] == '\0' || dest[0] == '\n')
		return (ft_verif_file(dest));
	return (i_need_lines(cube, dest));
}

int	init_map_du_bled(t_cube *cube)
{
	int		taille;
	char	*buf;
	char	*dest;

	taille = 1;
	buf = malloc(sizeof(char) * 4097);
	dest = malloc(sizeof(char) * 1);
	dest[0] = 0;
	while (taille > 0)
	{
		taille = read(0, buf, 4096);
		if (taille > 0)
		{
			buf[taille] = '\0';
			dest = ft_strncat_m(dest, buf, taille);
		}
	}
	free(buf);
	if (dest[0] == '\0' || dest[0] == '\n')
	{
		free(dest);
		return (0);
	}
	return (i_need_lines(cube, dest));
}
