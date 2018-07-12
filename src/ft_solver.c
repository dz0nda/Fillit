/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 18:00:14 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:44 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

void			ft_free_map(t_map *map)
{
	int			i;

	i = -1;
	while (++i < map->size)
		ft_strdel(&map->tab[i]);
}

int				ft_count_tetro(t_tetris *tetro)
{
	int nb;

	nb = 1;
	while (tetro->next != NULL)
	{
		tetro = tetro->next;
		nb++;
	}
	if (nb > 26)
		return (0);
	return (nb);
}

char			**ft_filling_map(char **map, t_tetris *tetro, int *index, int i)
{
	int itetro[3];
	int xtemp;
	int ytemp;

	itetro[0] = 0;
	itetro[1] = 0;
	itetro[2] = 4;
	xtemp = 0;
	ytemp = 0;
	while (ft_checkindex(tetro->tab, itetro, '#'))
	{
		if (i == 1)
			map[index[0]][index[1]] = tetro->letter;
		else
			map[index[0]][index[1]] = '.';
		ytemp = itetro[0];
		xtemp = itetro[1];
		itetro[1]++;
		if (ft_checkindex(tetro->tab, itetro, '#'))
		{
			index[1] += (itetro[1] - xtemp);
			index[0] += (itetro[0] - ytemp);
		}
	}
	return (map);
}

int				ft_solver_backtracking(t_tetris *tetro, t_map *map)
{
	int index[3];
	int indextmp[2];

	index[0] = 0;
	index[1] = 0;
	index[2] = map->size;
	if (tetro == NULL)
		return (1);
	while (ft_checkindex(map->tab, index, '.'))
	{
		if (ft_check_type(map->tab, index, tetro->type))
		{
			indextmp[0] = index[0];
			indextmp[1] = index[1];
			ft_filling_map(map->tab, tetro, indextmp, 1);
			if (ft_solver_backtracking(tetro->next, map))
				return (1);
			indextmp[0] = index[0];
			indextmp[1] = index[1];
			ft_filling_map(map->tab, tetro, indextmp, 0);
		}
		index[1] += 1;
	}
	return (0);
}

int				ft_solver(t_tetris *tetro)
{
	t_map		*map;
	int			nbtetros;

	if (!(nbtetros = ft_count_tetro(tetro)))
		return (0);
	map = create_map(nbtetros);
	while (!(ft_solver_backtracking(tetro, map)))
	{
		ft_free_map(map);
		map = create_map(++nbtetros);
	}
	ft_print_map(map);
	ft_free_map(map);
	return (1);
}
