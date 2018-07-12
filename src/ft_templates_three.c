/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_templates_three.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 21:55:05 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:49 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int			ft_checklup(char **tab, int *index, char c)
{
	if (index[0] + 1 < index[2] && index[1] - 2 >= 0)
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c)
			if (tab[index[0] + 1][index[1] - 1] == c &&
					tab[index[0] + 1][index[1] - 2] == c)
				return (41);
	return (0);
}

static int			ft_checkldo(char **tab, int *index, char c)
{
	if (index[0] + 1 < index[2] && index[1] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c)
			if (tab[index[0]][index[1] + 1] == c &&
					tab[index[0]][index[1] + 2] == c)
				return (42);
	return (0);
}

static int			ft_checklle(char **tab, int *index, char c)
{
	if (index[1] + 1 < index[2] && index[0] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0]][index[1] + 1] == c)
			if (tab[index[0] + 1][index[1] + 1] == c &&
					tab[index[0] + 2][index[1] + 1] == c)
				return (43);
	return (0);
}

static int			ft_checklri(char **tab, int *index, char c)
{
	if (index[1] + 1 < index[2] && index[0] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c)
			if (tab[index[0] + 2][index[1]] == c &&
					tab[index[0] + 2][index[1] + 1] == c)
				return (44);
	return (0);
}

int					ft_checkl(char **tab, int *index, char c, int type)
{
	int				i;

	i = 0;
	if (!type)
	{
		if ((i = ft_checklup(tab, index, c)))
			return (i);
		if ((i = ft_checkldo(tab, index, c)))
			return (i);
		if ((i = ft_checklle(tab, index, c)))
			return (i);
		if ((i = ft_checklri(tab, index, c)))
			return (i);
	}
	if (type == 41)
		return (ft_checklup(tab, index, c));
	if (type == 42)
		return (ft_checkldo(tab, index, c));
	if (type == 43)
		return (ft_checklle(tab, index, c));
	if (type == 44)
		return (ft_checklri(tab, index, c));
	return (0);
}
