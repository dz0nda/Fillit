/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:32:31 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:42 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

int						ft_sqrt(int nb)
{
	int					i;
	int					res;

	i = 0;
	res = 0;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (0);
	else
	{
		while (res != nb)
		{
			if (res > nb)
				return (i - 1);
			res = i * i;
			i++;
		}
	}
	return (i - 1);
}

t_map					*create_map(int nbtetros)
{
	t_map				*map;
	static int			itmp;
	int					i;
	int					x;

	i = -1;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (itmp != ft_sqrt(nbtetros * 4))
		itmp = ft_sqrt(nbtetros * 4);
	else
		itmp = ft_sqrt(nbtetros * 4) + 1;
	map->size = itmp;
	if (!(map->tab = (char **)malloc(sizeof(char *) * map->size)))
		return (NULL);
	while (++i < map->size)
	{
		x = -1;
		map->tab[i] = ft_strnew(map->size);
		while (++x < map->size)
			map->tab[i][x] = '.';
	}
	return (map);
}
