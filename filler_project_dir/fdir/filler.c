/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:58:21 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/15 17:42:05 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_input			g_f;
t_store			g_var_store[201];

int				ft_answer_direction(void)
{
	int			a;
	int			tmp;
	int			x;

	x = 0;
	a = 0;
	tmp = -1;
	while (g_var_store[a].i != -1)
	{
		if (g_var_store[a].enemy_direction > x)
		{
			x = g_var_store[a].enemy_direction;
			tmp = a;
		}
		a++;
	}
	return (tmp);
}

int				ft_answer_len_to_border(void)
{
	int			a;
	int			tmp;
	int			x;

	x = 0;
	a = 0;
	tmp = -1;
	while (g_var_store[a].i != -1)
	{
		if (g_var_store[a].len_to_border > x)
		{
			x = g_var_store[a].len_to_border;
			tmp = a;
		}
		a++;
	}
	if (tmp != -1)
		ft_border_update(tmp);
	return (tmp);
}

int				ft_answer(void)
{
	int			a;
	int			tmp;
	int			x;

	x = 0;
	a = 0;
	tmp = -1;
	if ((tmp = ft_answer_touch()) != -1)
		return (g_var_store[tmp].i);
	if ((tmp = ft_answer_direction()) != -1)
		return (g_var_store[tmp].i);
	ft_border_search();
	if ((tmp = ft_answer_len_to_border()) != -1)
		return (g_var_store[tmp].i);
	return (g_var_store[0].i);
}

int				ft_get_output(void)
{
	int			i;
	int			count;

	i = 0;
	while (g_f.plato[i] != '\0')
	{
		count = 0;
		if (PLATO)
		{
			count = ft_piece_cheker(i, 0, 0);
			if (count == 1)
				ft_count_store(i);
		}
		i++;
	}
	i = ft_answer();
	if (i != -1)
	{
		ft_piece_adder(i);
		if (ft_new_turn() == -1)
			return (-1);
		ft_get_output();
	}
	return (0);
}

int				main(void)
{
	g_f.fd = open("test0", O_RDWR | O_APPEND);
	if (ft_struct_clear() == -1)
		return (-1);
	if (ft_get_src() == -1)
		return (-1);
	ft_get_input();
	ft_get_output();
	ft_printf("0 0\n");
	return (0);
}
