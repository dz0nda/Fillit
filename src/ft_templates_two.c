/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_templates_two.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 21:48:11 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:49 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		ft_checkthup(char **tab, int *index, char c)
{
	if (index[1] - 1 >= 0 && index[1] + 1 < index[2] && index[0] + 1 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c &&
				tab[index[0] + 1][index[1] + 1] == c
				&& tab[index[0] + 1][index[1] - 1] == c)
			return (31);
	return (0);
}

static int		ft_checkthdo(char **tab, int *index, char c)
{
	if (index[1] + 2 < index[2] && index[0] + 1 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0]][index[1] + 1] == c &&
				tab[index[0]][index[1] + 2] == c
				&& tab[index[0] + 1][index[1] + 1] == c)
			return (32);
	return (0);
}

static int		ft_checktvle(char **tab, int *index, char c)
{
	if (index[1] - 1 >= 0 && index[0] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c &&
				tab[index[0] + 2][index[1]] == c)
			if (tab[index[0] + 1][index[1] - 1] == c)
				return (33);
	return (0);
}

static int		ft_checktvri(char **tab, int *index, char c)
{
	if (index[0] + 2 < index[2] && index[1] + 1 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c &&
				tab[index[0] + 2][index[1]] == c)
			if (tab[index[0] + 1][index[1] + 1] == c)
				return (34);
	return (0);
}

int				ft_checkt(char **tab, int *index, char c, int type)
{
	int i;

	i = 0;
	if (!type)
	{
		if ((i = ft_checktvle(tab, index, c)))
			return (i);
		if ((i = ft_checktvri(tab, index, c)))
			return (i);
		if ((i = ft_checkthup(tab, index, c)))
			return (i);
		if ((i = ft_checkthdo(tab, index, c)))
			return (i);
	}
	if (type == 31)
		return (ft_checkthup(tab, index, c));
	if (type == 32)
		return (ft_checkthdo(tab, index, c));
	if (type == 33)
		return (ft_checktvle(tab, index, c));
	if (type == 34)
		return (ft_checktvri(tab, index, c));
	return (0);
}
