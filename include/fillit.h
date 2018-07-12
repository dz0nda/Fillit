/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:39:34 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:31:43 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFFER_SIZE 4096
# include "../libft/include/libft.h"
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_map
{
	char			**tab;
	int				size;
}					t_map;

typedef struct		s_tetris
{
	char			**tab;
	char			letter;
	int				type;
	struct s_tetris *next;
}					t_tetris;

char				*ft_readfile(char *argv);
t_tetris			*ft_initgrid(char *fd, t_tetris *begin, int i);
int					ft_solver(t_tetris *tetro);
t_map				*create_map(int size);
int					ft_initchecktetro(char *str);
int					ft_check_all(char **tab, char c);
int					ft_checkindex(char **tab, int *index, char c);
int					ft_checki(char **tab, int *index, char c, int type);
int					ft_checko(char **tab, int *index, char c);
int					ft_checkt(char **tab, int *index, char c, int type);
int					ft_checkl(char **tab, int *index, char c, int type);
int					ft_checkj(char **tab, int *index, char c, int type);
int					ft_checkzs(char **tab, int *index, char c, int type);
int					ft_check_type(char **tab, int *index, char type);
void				ft_print_map(t_map *map);
void				ft_free_map(t_map *map);

#endif
