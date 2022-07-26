/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_keyboard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:09:06 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/03 22:55:16 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_search_player(t_so *so)
{
	int		i;
	size_t	j;

	i = 0;
	while (so->map[i])
	{
		j = 0;
		while (j < (so->wid - 1))
		{
			if (so->map[i][j] == 'P')
			{
				so->x_p = (int)j;
				so->y_p = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	ft_print_mouv(t_so *so)
{
	so->map[so->y_p + so->y][so->x_p + so->x] = 'P';
	so->map[so->y_p][so->x_p] = '0';
	so->mouv += 1;
	ft_printf("%d\n", so->mouv);
}

static int	ft_upgrade_map(t_so *so)
{
	ft_search_player(so);
	if (so->map[so->y_p + so->y][so->x_p + so->x] == '0')
		ft_print_mouv(so);
	else if (so->map[so->y_p + so->y][so->x_p + so->x] == 'C')
	{
		ft_print_mouv(so);
		so->c -= 1;
	}
	else if (so->map[so->y_p + so->y][so->x_p + so->x] == 'E' \
			&& so->c == 0)
	{	
		so->mouv += 1;
		so->winner = 1;
		ft_printf("\n*** Won in %d moves ***\n", so->mouv);
		ft_clear_so(so);
		return (1);
	}
	else if (so->map[so->y_p + so->y][so->x_p + so->x] == 'G')
		ft_game_over(so);
	ft_mouv_guardian(so);
	return (0);
}

static void	ft_orient_player(t_so *so)
{
	if (so->y == -1)
		so->direction = 'h';
	else if (so->y == 1)
		so->direction = 'b';
	else if (so->x == 1)
		so->direction = 'd';
	else if (so->x == -1)
		so->direction = 'g';
	ft_upgrade_pictures(so);
}

int	ft_update_map(int key, t_so *so)
{
	so->x = 0;
	so->y = 0;
	if (key == 13 || key == 126)
		so->y = -1;
	else if (key == 1 || key == 125)
		so->y = 1;
	else if (key == 2 || key == 124)
		so->x = 1;
	else if (key == 0 || key == 123)
		so->x = -1;
	else if (key == 53)
	{
		so->winner = 2;
		ft_printf("** See you next time **");
		ft_clear_so(so);
	}
	if (so->y != 0 || so->x != 0)
	{
		ft_orient_player(so);
		ft_upgrade_map(so);
		ft_print_mac(so);
	}
	return (0);
}
