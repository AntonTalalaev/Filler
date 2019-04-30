/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_tool_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:40:57 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/15 17:41:00 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_get_xy(void)
{
	char		*p;
	int			i;

	i = 0;
	p = ft_strstr(g_f.src, "Plateau");
	while (!ft_isdigit(*p))
		p++;
	g_f.plato_y = ft_atoi(p);
	while (ft_isdigit(*p))
		p++;
	g_f.plato_x = ft_atoi(p);
	p = ft_strstr(p, "Piece");
	ft_bzero(p, 6);
	while (!ft_isdigit(*p))
		p++;
	g_f.piece_y = ft_atoi(p);
	while (ft_isdigit(*p))
		p++;
	g_f.piece_x = ft_atoi(p);
	p = ft_strchr(p, '\n');
	g_f.piece = ++p;
	i = (g_f.piece_x + 1) * g_f.piece_y - 1;
	while (i-- >= 0)
		read(0, p++, 1);
	g_f.plato_last = (g_f.plato_x + 5) * g_f.plato_y - 2;
}

void			ft_get_input(void)
{
	char		*p;
	int			i;

	i = 0;
	p = ft_strchr(g_f.src, 'p');
	p++;
	(*p == '1') ? (g_f.p_char = 'O') : (1);
	(*p == '2') ? (g_f.p_char = 'X') : (1);
	ft_get_xy();
	g_f.plato = ft_strstr(p, "000 ");
	p = ft_strrchr(g_f.piece, '*');
	p = ft_strchr(p, '\n');
	*p = '\0';
	while (g_f.plato[i] != g_f.p_char)
		i++;
	while (g_f.plato[i - g_f.left] != ' ')
		g_f.left++;
	g_f.left--;
	while (g_f.plato[i + g_f.right] != '\n')
		g_f.right++;
	g_f.right--;
	while (g_f.plato[i] != '\n')
		i--;
	g_f.up = ft_atoi(&g_f.plato[i]);
	g_f.down = (g_f.plato_y - 1) - g_f.up;
}

int				ft_piece_cheker(int i, int a, int count)
{
	while (g_f.piece[a] != '\0')
	{
		if (g_f.piece[a] == '*')
			if (CHAR)
			{
				if (CHAR_PL)
					count++;
				else
					return (-1);
			}
		if (g_f.plato[i] == '\n' || i > g_f.plato_last)
			return (-1);
		if (g_f.piece[a + 1] == '\n')
		{
			i = i + g_f.plato_x + 5 - (g_f.piece_x - 1);
			a += 2;
		}
		else
		{
			a++;
			i++;
		}
	}
	return (count);
}
