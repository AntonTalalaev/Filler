/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_tool_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:41:27 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/15 17:41:29 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_dest_enemy_diagonal_down_right(int i, int a)
{
	int			len;
	int			high;
	int			x;

	x = 0;
	high = CHECK_ENEMY_HIGH;
	len = CHECK_ENEMY_LEN;
	while (high-- > 0 && len-- > 0 && g_f.plato[i] == '.')
	{
		i += (g_f.plato_x + 5) + 1;
		x++;
	}
	if (CHAR_ENEMY)
		if (g_var_store[a].enemy_direction > x)
			g_var_store[a].enemy_direction = x;
}

void			ft_dest_enemy_diagonal_up_right(int i, int a)
{
	int			len;
	int			high;
	int			x;

	x = 0;
	high = CHECK_ENEMY_HIGH;
	len = CHECK_ENEMY_LEN;
	while (high-- > 0 && len-- > 0 && g_f.plato[i] == '.')
	{
		i -= (g_f.plato_x + 5) + 1;
		x++;
	}
	if (CHAR_ENEMY)
		if (g_var_store[a].enemy_direction > x)
			g_var_store[a].enemy_direction = x;
}

void			ft_dest_enemy_diagonal_down_left(int i, int a)
{
	int			len;
	int			high;
	int			x;

	x = 0;
	high = CHECK_ENEMY_HIGH;
	len = CHECK_ENEMY_LEN;
	while (high-- > 0 && len-- > 0 && g_f.plato[i] == '.')
	{
		i += (g_f.plato_x + 5) - 1;
		x++;
	}
	if (CHAR_ENEMY)
		if (g_var_store[a].enemy_direction > x)
			g_var_store[a].enemy_direction = x;
}

void			ft_dest_enemy_diagonal_up_left(int i, int a)
{
	int			len;
	int			high;
	int			x;

	x = 0;
	high = CHECK_ENEMY_HIGH;
	len = CHECK_ENEMY_LEN;
	while (high-- > 0 && len-- > 0 && g_f.plato[i] == '.')
	{
		i -= (g_f.plato_x + 5) - 1;
		x++;
	}
	if (CHAR_ENEMY)
		if (g_var_store[a].enemy_direction > x)
			g_var_store[a].enemy_direction = x;
}

void			ft_dest_enemy(int i, int a)
{
	g_var_store[a].enemy_direction = 0;
	ft_dest_enemy_left_right(i, a);
	ft_dest_enemy_up_down(i, a);
	ft_dest_enemy_diagonal_down_right(i, a);
	ft_dest_enemy_diagonal_down_left(i, a);
	ft_dest_enemy_diagonal_up_left(i, a);
	ft_dest_enemy_diagonal_up_right(i, a);
}
