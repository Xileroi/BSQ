/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:31:48 by yalounic          #+#    #+#             */
/*   Updated: 2023/05/14 09:05:02 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bbq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

void	init_tab(t_cube *cube, char *map_txt)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map_txt[j] != '\n')
		j++;
	malloc_tab(cube, map_txt);
	j++;
	while (i < cube->nb_line)
	{
		while (map_txt[j] != '\n' && map_txt[j] != '\0')
		{
			cube->map[i][k] = map_txt[j];
			k++;
			j++;
		}
		if (map_txt[j] == '\n')
			j++;
		cube->map[i][k] = '\0';
		k = 0;
		i++;
	}
}
