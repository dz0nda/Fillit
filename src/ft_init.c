/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 02:27:52 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:42 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

char				*ft_readfile(char *argv)
{
	int				fd;
	int				readfd;
	char			buff[BUFFER_SIZE + 1];
	char			*str;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while ((readfd = read(fd, buff, BUFFER_SIZE)))
		buff[readfd] = '\0';
	if (close(fd) == -1)
		return (0);
	str = ft_strdup(buff);
	return (str);
}

static void			ft_lstaddtetro(t_tetris **begin, t_tetris *new)
{
	while (*begin)
		begin = &(*begin)->next;
	new->next = *begin;
	*begin = new;
}

static t_tetris		*ft_tetronew(char **grid, int letter, int type)
{
	t_tetris		*element;

	if (!(element = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!(element->tab = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	element->tab = grid;
	element->letter = 'A' + letter;
	element->type = type;
	element->next = NULL;
	return (element);
}

t_tetris			*ft_initgrid(char *fd, t_tetris *begin, int i)
{
	int				letter;
	char			type;
	char			*str;
	char			**grid;
	t_tetris		*tetros;

	letter = -1;
	tetros = NULL;
	begin = tetros;
	while (((size_t)i) < ft_strlen(fd))
	{
		if (((size_t)i + 21 == ft_strlen(fd)))
			return (0);
		if (!ft_initchecktetro(str = ft_strsub(fd, (unsigned)i, 21)))
			return (0);
		grid = ft_strsplit(str, '\n');
		if (!(type = ft_check_all(grid, '#')))
			return (0);
		tetros = ft_tetronew(grid, ++letter, type);
		ft_lstaddtetro(&begin, tetros);
		i += 21;
	}
	return (begin);
}
