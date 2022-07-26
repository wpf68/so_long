/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouv_guardian.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:36:13 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/05 16:10:43 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_guardians(int i, int j, t_so *so)
{
	int	x;
	int	y;

	y = 0;
	x = (((so->mouv * 3 + so->x_p + so->y_p) * 2) % 3) - 1;
	if (x == 0)
		y = (((so->mouv + so->x_p)) % 3) - 1;
	if (so->map[y + i][x + j] == '0')
	{
		so->map[y + i][x + j] = 'G';
		so->map[i][j] = '0';
	}
	else if (so->map[y + i][x + j] == 'P')
		ft_game_over(so);
}

static void	ft_search_guardians(t_so *so)
{
	int	i;
	int	j;
	int	guardian;

	i = 0;
	guardian = 1;
	while (so->map[i] && guardian)
	{
		j = 0;
		while (j < (int)(so->wid - 1))
		{
			if (so->map[i][j] == 'G')
			{
				ft_guardians(i, j, so);
				guardian = 0;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_game_over(t_so *so)
{
	ft_printf("\n*** Game Over in %d moves ***\n", so->mouv);
	ft_clear_so(so);
}

void	ft_mouv_guardian(t_so *so)
{
	ft_printf("\n--- mouve guardians");
	ft_search_guardians(so);
}
