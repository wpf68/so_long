/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:52:21 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/05 16:16:08 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"
# include "../libft_total/libft.h"

typedef struct s_so{
	char	**map;
	int		fd;
	int		hei;
	size_t	wid;
	int		c;
	int		p;
	int		e;
	int		x;
	int		y;
	int		x_p;
	int		y_p;
	int		mouv;
	int		count;
	void	*mlx;
	void	*wim;
	void	*img;
	void	*pl;
	void	*cr;
	void	*ex;
	void	*wall;
	void	*water;
	void	*guardian;
	char	direction;
	int		winner;
	int		key;
	char	temp;
}		t_so;

int		ft_test_argv(char *argv);
int		ft_load(t_so *so, char *argv);
int		ft_clear_so(t_so *so);
int		ft_update_map(int key, t_so *so);
int		ft_print_mac(t_so *so);
void	ft_init_sprite(t_so *so);
void	ft_init_windows(t_so *so);
void	ft_upgrade_pictures(t_so *so);
void	ft_mouv_guardian(t_so *so);
void	ft_game_over(t_so *so);

#endif
