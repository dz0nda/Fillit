/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_templates_four.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 22:00:28 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:47 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int			ft_checkjup(char **tab, int *index, char c)
{
	if (index[0] + 1 < index[2] && index[1] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c)
			if (tab[index[0] + 1][index[1] + 1] == c &&
					tab[index[0] + 1][index[1] + 2] == c)
				return (51);
	return (0);
}

static int			ft_checkjdo(char **tab, int *index, char c)
{
	if (index[0] + 1 < index[2] && index[1] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0]][index[1] + 1] == c)
			if (tab[index[0]][index[1] + 2] == c &&
					tab[index[0] + 1][index[1] + 2] == c)
				return (52);
	return (0);
}

static int			ft_checkjle(char **tab, int *index, char c)
{
	if (index[1] - 1 < index[2] && index[0] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c)
			if (tab[index[0] + 2][index[1]] == c &&
					tab[index[0] + 2][index[1] - 1] == c)
				return (53);
	return (0);
}

static int			ft_checkjri(char **tab, int *index, char c)
{
	if (index[1] + 1 < index[2] && index[0] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0]][index[1] + 1] == c)
			if (tab[index[0] + 1][index[1]] == c &&
					tab[index[0] + 2][index[1]] == c)
				return (54);
	return (0);
}

int					ft_checkj(char **tab, int *index, char c, int type)
{
	int				i;

	i = 0;
	if (!type)
	{
		if ((i = ft_checkjup(tab, index, c)))
			return (i);
		if ((i = ft_checkjdo(tab, index, c)))
			return (i);
		if ((i = ft_checkjle(tab, index, c)))
			return (i);
		if ((i = ft_checkjri(tab, index, c)))
			return (i);
	}
	if (type == 51)
		return (ft_checkjup(tab, index, c));
	if (type == 52)
		return (ft_checkjdo(tab, index, c));
	if (type == 53)
		return (ft_checkjle(tab, index, c));
	if (type == 54)
		return (ft_checkjri(tab, index, c));
	return (0);
}
