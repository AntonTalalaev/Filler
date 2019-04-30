/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_tool_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:41:12 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/15 17:41:14 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_piece_adder(int i)
{
	int			x;
	int			y;

	x = -1;
	while (PLATO)
	{
		i--;
		x++;
	}
	while (g_f.plato[i] != '\n' && i > 0)
		i--;
	y = ft_atoi(&g_f.plato[i]);
	ft_printf("%file~x = %d, y = %d\n", g_f.fd, x, y);
	ft_printf("%d %d\n", y, x);
}

int				ft_get_src(void)
{
	int			i;
	char		c;

	i = 0;
	while (read(0, &c, 1) == 1)
	{
		g_f.src[i] = c;
		if (c == '\n' && g_f.src[i - 1] == ':' && ft_strstr(g_f.src, "Piece"))
			break ;
		i++;
	}
	if (i == 0)
		return (-1);
	return (0);
}

int				ft_new_turn(void)
{
	ft_memdel((void **)&g_f.src);
	if (ft_struct_clear() == -1)
		return (-1);
	if (ft_get_src() == -1)
		return (-1);
	ft_get_xy();
	g_f.plato = ft_strstr(g_f.src, "\n000 ");
	return (0);
}

/*
** g_var_store[a].enemy_direction - show distance to the enemy
*/

void			ft_dest_enemy_left_right(int i, int a)
{
	int			len;
	int			x;
	int			i2;

	i2 = i;
	len = CHECK_ENEMY_LEN;
	while (len-- > 0 && g_f.plato[i] == '.')
		i--;
	x = i2 - i;
	if (CHAR_ENEMY)
		g_var_store[a].enemy_direction = x;
	i = i2;
	len = CHECK_ENEMY_LEN;
	while (len-- > 0 && g_f.plato[i] == '.')
		i++;
	x = i - i2;
	if (CHAR_ENEMY)
		if (g_var_store[a].enemy_direction > x)
			g_var_store[a].enemy_direction = x;
}

void			ft_dest_enemy_up_down(int i, int a)
{
	int			high;
	int			x;
	int			i2;

	i2 = i;
	x = 0;
	high = CHECK_ENEMY_HIGH;
	while (high-- > 0 && g_f.plato[i] == '.')
	{
		i += (g_f.plato_x + 5);
		x++;
	}
	if (CHAR_ENEMY)
		if (g_var_store[a].enemy_direction > x)
			g_var_store[a].enemy_direction = x;
	i = i2;
	high = CHECK_ENEMY_HIGH;
	while (high-- > 0 && g_f.plato[i] == '.')
	{
		i -= (g_f.plato_x + 5);
		x++;
	}
	if (CHAR_ENEMY)
		if (g_var_store[a].enemy_direction > x)
			g_var_store[a].enemy_direction = x;
}
