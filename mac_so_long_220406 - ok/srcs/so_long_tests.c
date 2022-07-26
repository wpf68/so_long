/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:16:46 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/06 10:35:59 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_map(t_so *so)
{
	int		i;
	size_t	j;
	char	c;

	i = -1;
	while (so->map[++i])
	{
		j = 0;
		while (j < (so->wid - 1))
		{
			c = so->map[i][j];
			if (c == 'C')
				so->c += 1;
			else if (c == 'P')
				so->p += 1;
			else if (c == 'E')
				so->e += 1;
			else if (c != '1' && c != '0' && c != '\n' && c != 'G')
				return (1);
			j++;
		}
	}
	if (so->c == 0 || so->p != 1 || so->e == 0)
		return (1);
	return (0);
}

static int	ft_check_map(t_so *so)
{
	size_t	i;

	so->wid = ft_strlen(so->map[0]);
	if (so->wid < 4 || so->map[0][0] != '1')
		return (1);
	i = 0;
	while (so->map[0][i] != '\n' && so->map[so->hei - 1][i] != '\n')
	{
		if (so->map[0][i] != '1' || so->map[so->hei - 1][i] != '1')
			return (1);
		i++;
	}
	if (ft_strlen(so->map[so->hei - 1]) != so->wid || (i + 1) != so->wid)
		return (1);
	i = 1;
	while ((int)i < (so->hei - 1))
	{
		if (ft_strlen(so->map[i]) != so->wid || so->map[i][0] != '1' \
				|| so->map[i][so->wid - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_load_map(t_so *so, char *argv)
{
	char	*temp;
	int		i;
	int		j;

	temp = ft_strjoin("maps/", argv);
	so->fd = open(temp, O_RDONLY);
	free(temp);
	if (so->fd == -1 || so->hei < 2)
		return (1);
	so->map = malloc(sizeof(so->map) * (so->hei + 1));
	if (!(so->map))
		return (1);
	i = -1;
	while (++i <= so->hei)
		so->map[i] = get_next_line(so->fd);
	i = ft_check_map(so);
	j = ft_count_map(so);
	if (i || j)
	{
		so->winner = 3;
		ft_clear_so(so);
	}
	return (0);
}

int	ft_test_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] == 'r' && argv[i - 2] == 'e' && argv[i - 3] == 'b'\
		&& argv[i - 4] == '.')
		return (0);
	return (1);
}

int	ft_load(t_so *so, char *argv)
{
	char	*temp;
	int		test;

	temp = ft_strjoin("maps/", argv);
	so->fd = open(temp, O_RDONLY);
	free(temp);
	if (so->fd == -1)
		return (1);
	so->hei = 0;
	temp = get_next_line(so->fd);
	while (temp)
	{
		so->hei += 1;
		free(temp);
		temp = get_next_line(so->fd);
	}
	close(so->fd);
	ft_printf("--- load 2 ---- \n");
	test = ft_load_map(so, argv);
	ft_printf("--- load ---- \n");
	return (test);
}
