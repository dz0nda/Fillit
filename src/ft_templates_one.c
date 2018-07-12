/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_templates_one.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 22:24:30 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:48 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		ft_checkih(char **tab, int *index, char c)
{
	if (index[0] + 3 < index[2])
		if (tab[index[0]][index[1]] == c)
			if (tab[index[0] + 1][index[1]] == c)
				if (tab[index[0] + 2][index[1]] == c &&
						tab[index[0] + 3][index[1]] == c)
					return (1);
	return (0);
}

static int		ft_checkiv(char **tab, int *index, char c)
{
	if (index[1] + 3 < index[2])
	{
		if (tab[index[0]][index[1]] == c)
			if (tab[index[0]][index[1] + 1] == c)
				if (tab[index[0]][index[1] + 2] == c &&
						tab[index[0]][index[1] + 3] == c)
					return (11);
	}
	return (0);
}

int				ft_checki(char **tab, int *index, char c, int type)
{
	int i;

	i = 0;
	if (!type)
	{
		if ((i = ft_checkih(tab, index, c)))
			return (i);
		if ((i = ft_checkiv(tab, index, c)))
			return (i);
	}
	if (type == 1)
		return (ft_checkih(tab, index, c));
	if (type == 11)
		return (ft_checkiv(tab, index, c));
	return (0);
}

int				ft_checko(char **tab, int *index, char c)
{
	if (index[0] + 1 < index[2] && index[1] + 1 < index[2])
		if (tab[index[0]][index[1]] == c && tab[index[0]][index[1] + 1] == c &&
				tab[index[0] + 1][index[1]] == c)
			if (tab[index[0] + 1][index[1] + 1] == c)
				return (2);
	return (0);
}
