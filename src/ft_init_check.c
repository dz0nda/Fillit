/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 02:24:52 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:30:43 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int	ft_init_checkchar(char c, int *dot, int *hashtag)
{
	if (c != '.' && c != '#')
		return (0);
	if (c == '.')
		*dot += 1;
	if (c == '#')
		*hashtag += 1;
	return (1);
}

static int	ft_init_checknchar(int dot, int hashtag)
{
	if (dot != 12 || hashtag != 4)
		return (0);
	return (1);
}

int			ft_initchecktetro(char *str)
{
	int i;
	int dot;
	int hashtag;
	int count;

	i = 0;
	dot = 0;
	hashtag = 0;
	count = 0;
	while (i < 19)
	{
		if (!ft_init_checkchar(str[i], &dot, &hashtag))
			return (0);
		if (str[++i] == '\n' || str[i] == '\r')
		{
			if ((dot + hashtag) / ++count != 4)
				return (0);
			else
				i++;
		}
	}
	if (!ft_init_checknchar(dot, hashtag) && (str[i] != '\n' || str[i] != '\0'))
		return (0);
	return (1);
}
