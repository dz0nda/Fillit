/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 15:12:42 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:41 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_checkindex(char **tab, int *index, char c)
{
	while (index[0] < index[2])
	{
		while (index[1] < index[2])
		{
			if (tab[index[0]][index[1]] == c)
				return (1);
			index[1] += 1;
		}
		index[1] = 0;
		index[0] += 1;
	}
	return (0);
}

int		ft_check_all(char **tab, char c)
{
	int index[3];
	int i;

	index[0] = 0;
	index[1] = 0;
	index[2] = 4;
	i = 0;
	if (ft_checkindex(tab, index, c))
	{
		if ((i = ft_checki(tab, index, c, 0)))
			return (i);
		if ((i = ft_checko(tab, index, c)))
			return (i);
		if ((i = ft_checkt(tab, index, c, 0)))
			return (i);
		if ((i = ft_checkl(tab, index, c, 0)))
			return (i);
		if ((i = ft_checkj(tab, index, c, 0)))
			return (i);
		if ((i = ft_checkzs(tab, index, c, 0)))
			return (i);
	}
	return (0);
}

int		ft_check_type(char **tab, int *index, char type)
{
	if (type == 1 || type == 11)
		return (ft_checki(tab, index, '.', type));
	if (type == 2)
		return (ft_checko(tab, index, '.'));
	if (type > 30 && type < 35)
		return (ft_checkt(tab, index, '.', type));
	if (type > 40 && type < 45)
		return (ft_checkl(tab, index, '.', type));
	if (type > 50 && type < 55)
		return (ft_checkj(tab, index, '.', type));
	if (type == 61 || type == 62 || type == 71 || type == 72)
		return (ft_checkzs(tab, index, '.', type));
	return (0);
}
