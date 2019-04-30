/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_tool_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:41:55 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/15 17:41:57 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_count_store(int i)
{
	int			a;
	int			q;

	a = ft_count_store_new_var(i);
	q = 0;
	while (g_f.piece[q] != '\0')
	{
		if (g_f.piece[q] == '*')
			ft_count_store_border_check(i, a);
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

void			ft_border_search_tool(int a, int tmp, int x)
{
	if (g_f.up != 0)
	{
		x = g_f.up - g_var_store[a].up;
		if (x > tmp)
			tmp = x;
	}
	if (g_f.down != 0)
	{
		x = g_f.down - g_var_store[a].down;
		if (x > tmp)
			tmp = x;
	}
	if (g_f.left != 0)
	{
		x = g_f.left - g_var_store[a].left;
		if (x > tmp)
			tmp = x;
	}
	if (g_f.right != 0)
	{
		x = g_f.right - g_var_store[a].right;
		if (x > tmp)
			tmp = x;
	}
	g_var_store[a].len_to_border = tmp;
}

void			ft_border_search(void)
{
	int			x;
	int			tmp;
	int			a;

	x = 0;
	tmp = 0;
	a = 0;
	while (g_var_store[a].i != -1)
	{
		ft_border_search_tool(a, tmp, x);
		a++;
	}
}

void			ft_border_update(int a)
{
	if (g_var_store[a].left < g_f.left)
		g_f.left = g_var_store[a].left;
	if (g_var_store[a].right < g_f.right)
		g_f.right = g_var_store[a].right;
	if (g_var_store[a].up < g_f.up)
		g_f.up = g_var_store[a].up;
	if (g_var_store[a].down < g_f.down)
		g_f.down = g_var_store[a].down;
}

int				ft_answer_touch(void)
{
	int			a;
	int			tmp;
	int			x;

	x = 0;
	a = 0;
	tmp = -1;
	while (g_var_store[a].i != -1)
	{
		if (g_var_store[a].touch > x)
		{
			x = g_var_store[a].touch;
			tmp = a;
		}
		a++;
	}
	return (tmp);
}
