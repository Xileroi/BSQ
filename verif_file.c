/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:23:16 by yalounic          #+#    #+#             */
/*   Updated: 2023/05/14 09:05:03 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bbq.h"

int	ft_verif_file(char *dest)
{
	free(dest);
	return (0);
}

int	apelle(char *str, t_cube *cube, int save)
{
	if (str[save] == '\0')
		return (0);
	return (ft_check_first(str, cube, save));
}
