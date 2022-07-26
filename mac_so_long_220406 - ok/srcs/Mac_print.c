/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mac_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:05:42 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/05 16:16:45 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_windows(char c, int j, int i, t_so *so)
{
	int	x;
	int	y;

	x = j * 100;
	y = i * 100 + 100;
	if (c == '1')
		mlx_put_image_to_window(so->mlx, so->wim, so->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(so->mlx, so->wim, so->water, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(so->mlx, so->wim, so->cr, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(so->mlx, so->wim, so->ex, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(so->mlx, so->wim, so->pl, x, y);
	else if (c == 'G')
		mlx_put_image_to_window(so->mlx, so->wim, so->guardian, x, y);
}

int	ft_print_mac(t_so *so)
{
	int		i;
	int		j;
	char	c;
	char	*mouv_c;

	i = 0;
	while (so->map[i])
	{
		j = 0;
		while (so->map[i][j] != '\n')
		{
			c = so->map[i][j];
			ft_put_windows(c, j, i, so);
			j++;
		}
		i++;
	}
	mouv_c = ft_itoa(so->mouv);
	ft_printf("--- 3 -- ---- mouv = %s  \n", mouv_c);
	mlx_string_put(so->mlx, so->wim, 50, 50, 0xFFFFFF, mouv_c);
	free(mouv_c);
	return (0);
}

static char	*ft_init_patch(char *path, int nb, t_so *so)
{
	char	c[2];
	char	*temp;
	char	*pathf;

	c[0] = so->direction;
	c[1] = '\0';
	pathf = NULL;
	if (so->direction)
		pathf = ft_strjoin(path, c);
	else
		pathf = ft_strjoin(path, "");
	temp = pathf;
	c[0] = (so->count) % nb + 49;
	pathf = ft_strjoin(temp, c);
	free(temp);
	ft_printf("count = %d c = %s path = %s\n", so->count, c, pathf);
	temp = pathf;
	pathf = ft_strjoin(temp, ".xpm");
	free(temp);
	return (pathf);
}

void	ft_init_sprite(t_so *so)
{
	int			wi;
	int			he;
	static char	path_cr[] = "./pictures/Shrimp.xpm";
	char		*path;

	so->temp = so->direction;
	so->count = so->count + 1;
	so->cr = mlx_xpm_file_to_image(so->mlx, path_cr, &wi, &he);
	path = ft_init_patch("./pictures/dauphin", 4, so);
	so->direction = '\0';
	so->pl = mlx_xpm_file_to_image(so->mlx, path, &wi, &he);
	free(path);
	path = ft_init_patch("./pictures/Exit", 4, so);
	so->ex = mlx_xpm_file_to_image(so->mlx, path, &wi, &he);
	free(path);
	path = ft_init_patch("./pictures/recif", 2, so);
	so->wall = mlx_xpm_file_to_image(so->mlx, path, &wi, &he);
	free(path);
	path = ft_init_patch("./pictures/water", 2, so);
	so->water = mlx_xpm_file_to_image(so->mlx, path, &wi, &he);
	free(path);
	path = ft_init_patch("./pictures/pieuvre", 2, so);
	so->guardian = mlx_xpm_file_to_image(so->mlx, path, &wi, &he);
	free(path);
	so->direction = so->temp;
}

void	ft_upgrade_pictures(t_so *so)
{
	ft_printf("ft_upgrade_picture entree  \n");
	mlx_clear_window(so->mlx, so->wim);
	ft_printf("ft_upgrade_picture sortie \n");
	ft_init_sprite(so);
}
