/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:10:58 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/06 10:32:58 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_clear_so(t_so *so)
{
	int	i;

	i = 0;
	while (so->map[i])
	{
		free(so->map[i]);
		i++;
	}
	free(so->map);
	if (so->winner == 3)
		exit (0);
	mlx_destroy_image(so->mlx, so->pl);
	mlx_destroy_image(so->mlx, so->cr);
	mlx_destroy_image(so->mlx, so->ex);
	mlx_destroy_image(so->mlx, so->wall);
	mlx_destroy_image(so->mlx, so->water);
	mlx_destroy_window(so->mlx, so->wim);
	exit(0);
	return (0);
}
