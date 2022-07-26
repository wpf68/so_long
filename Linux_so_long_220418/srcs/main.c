/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:53:30 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/05 16:12:36 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Run ::  make run --> (with map0.ber)  */

static void	ft_init_so(t_so *so)
{
	so->c = 0;
	so->p = 0;
	so->e = 0;
	so->key = 0;
	so->mouv = 0;
	so->direction = 'd';
	so->pl = NULL;
	so->cr = NULL;
	so->ex = NULL;
	so->wall = NULL;
	so->water = NULL;
	so->winner = 0;
	so->count = 0;
}

void	ft_init_windows(t_so *so)
{
	int	height;
	int	width;

	height = (so->hei + 2) * 100;
	width = ((int)so->wid) * 100;
	so->mlx = mlx_init();
	so->wim = mlx_new_window(so->mlx, width, height, "so_long");
	so->img = mlx_new_image(so->mlx, width, height);
	if (!so->wim || !so->img || !so->mlx)
	{
		so->winner = 4;
		ft_clear_so(so);
	}
}

int	ft_refresh_screen(t_so *so)
{
	static int	frame;

	frame++;
	if (frame > 2200)
	{
		ft_init_sprite(so);
		ft_print_mac(so);
		frame = 0;
		ft_mouv_guardian(so);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_so	so;

	if (argc != 2 || ft_test_argv(argv[1]))
		return (ft_printf(" -- error argv -- \n"));
	ft_init_so(&so);
	if (ft_load(&so, argv[1]))
		return (ft_printf(" -- error map -- \n"));
	ft_init_windows(&so);
	ft_init_sprite(&so);
	ft_print_mac(&so);
	mlx_loop_hook(so.mlx, ft_refresh_screen, &so);
	ft_printf("mlx = %p\n", so.mlx);
	mlx_hook(so.wim, 2, 1L << 0, ft_update_map, &so);
	mlx_hook(so.wim, 17, 1L << 17, ft_clear_so, &so);
	mlx_loop(so.mlx);
	return (0);
}
