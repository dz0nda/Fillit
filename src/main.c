/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:03:52 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:32:12 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		ft_false(int i)
{
	if (i == 0)
		ft_putendl("error");
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}

int				main(int argc, char **argv)
{
	char		*file;
	t_tetris	*tetro;

	if (!(tetro = (t_tetris *)malloc(sizeof(t_tetris))))
		return (0);
	if (argc != 2)
		return (ft_false(1));
	if ((file = ft_readfile(argv[1])) == NULL)
	{
		ft_strdel(&file);
		return (ft_false(1));
	}
	if (!(tetro = ft_initgrid(file, tetro, 0)))
	{
		free(tetro);
		return (ft_false(0));
	}
	if (!(ft_solver(tetro)))
		return (ft_false(0));
	return (0);
}
