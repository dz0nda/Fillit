/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_templates_five.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 22:16:30 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:46 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int			ft_checkzh(char **tab, int *index, char c)
{
	if ((index[1] + 2) < index[2] && (index[0] + 1) < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0]][index[1] + 1] == c)
			if (tab[index[0] + 1][index[1] + 1] == c &&
					tab[index[0] + 1][index[1] + 2] == c)
				return (61);
	return (0);
}

static int			ft_checkzv(char **tab, int *index, char c)
{
	if (index[1] - 1 >= 0 && index[0] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c)
			if (tab[index[0] + 1][index[1] - 1] == c &&
					tab[index[0] + 2][index[1] - 1] == c)
				return (62);
	return (0);
}

static int			ft_checksh(char **tab, int *index, char c)
{
	if (index[1] - 1 >= 0 && index[1] + 1 < index[2] && index[0] + 1 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0]][index[1] + 1] == c)
			if (tab[index[0] + 1][index[1]] == c &&
					tab[index[0] + 1][index[1] - 1] == c)
				return (71);
	return (0);
}

static int			ft_checksv(char **tab, int *index, char c)
{
	if (index[1] + 1 < index[2] && index[0] + 2 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0] + 1][index[1]] == c)
			if (tab[index[0] + 1][index[1] + 1] == c &&
					tab[index[0] + 2][index[1] + 1] == c)
				return (72);
	return (0);
}

int					ft_checkzs(char **tab, int *index, char c, int type)
{
	int i;

	i = 0;
	if (!type)
	{
		if ((i = ft_checkzh(tab, index, c)))
			return (i);
		if ((i = ft_checkzv(tab, index, c)))
			return (i);
		if ((i = ft_checksh(tab, index, c)))
			return (i);
		if ((i = ft_checksv(tab, index, c)))
			return (i);
	}
	if (type == 61)
		return (ft_checkzh(tab, index, c));
	if (type == 62)
		return (ft_checkzv(tab, index, c));
	if (type == 71)
		return (ft_checksh(tab, index, c));
	if (type == 72)
		return (ft_checksv(tab, index, c));
	return (0);
}
