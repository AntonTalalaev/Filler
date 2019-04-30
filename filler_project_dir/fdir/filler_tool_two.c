/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_tool_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:41:38 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/15 17:50:14 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** checking if the enemy is on the nearest block (and how much such blocks)
*/

void			ft_touch_enemy_left_up(int i, int a)
{
	int			x;

	i--;
	if (CHAR_ENEMY)
		g_var_store[a].touch++;
	if (i - (g_f.plato_x + 5) > 0)
	{
		i = i - (g_f.plato_x + 5);
		if (CHAR_ENEMY)
			g_var_store[a].touch++;
	}
	x = 0;
	while (++x <= 3)
	{
		i++;
		if (CHAR_ENEMY)
			g_var_store[a].touch++;
	}
}

void			ft_touch_enemy_right_down(int i, int a)
{
	int			x;

	i++;
	if (CHAR_ENEMY)
		g_var_store[a].touch++;
	if (i + (g_f.plato_x + 5) <= g_f.plato_last)
	{
		i = i - (g_f.plato_x + 5);
		if (CHAR_ENEMY)
			g_var_store[a].touch++;
	}
	x = 0;
	while (++x <= 3)
	{
		i--;
		if (CHAR_ENEMY)
			g_var_store[a].touch++;
	}
}

void			ft_touch_enemy(int i, int a)
{
	int			q;

	q = 0;
	g_var_store[a].touch = 0;
	while (g_f.piece[q] != '\0')
	{
		if (g_f.piece[q] == '*')
		{
			ft_touch_enemy_left_up(i, a);
			ft_touch_enemy_right_down(i, a);
			if (g_var_store[a].touch == 0)
				ft_dest_enemy(i, a);
		}
		if (g_f.piece[q + 1] == '\n')
		{
			i = i + g_f.plato_x + 5 - (g_f.piece_x - 1);
			q += 2;
		}
		else
		{
			i++;
			q++;
		}
	}
}

int				ft_count_store_new_var(int i)
{
	int			a;

	a = 0;
	while (g_var_store[a].i != -1)
	{
		a++;
		if (a == 200)
		{
			ft_printf("%file~ERROR: g_var_store full\n", g_f.fd);
			break ;
		}
	}
	g_var_store[a].i = i;
	g_var_store[a].left = g_f.left;
	g_var_store[a].right = g_f.right;
	g_var_store[a].up = g_f.up;
	g_var_store[a].down = g_f.down;
	g_var_store[a].touch = 0;
	return (a);
}

void			ft_count_store_border_check(int i, int a)
{
	int			x;

	x = 0;
	while (g_f.plato[i + x] != '\n')
		x++;
	x--;
	if (x < g_var_store[a].right)
		g_var_store[a].right = x;
	x = 0;
	while (g_f.plato[i - x] != ' ')
		x++;
	if (--x < g_var_store[a].left)
		g_var_store[a].left = x;
	while (g_f.plato[i - x] != '\n')
		x++;
	x = ft_atoi(&g_f.plato[i - x]);
	if (x < g_var_store[a].up)
		g_var_store[a].up = x;
	x = (g_f.plato_y) - x;
	if (--x < g_var_store[a].down)
		g_var_store[a].down = x;
	ft_touch_enemy(g_var_store[a].i, a);
}
