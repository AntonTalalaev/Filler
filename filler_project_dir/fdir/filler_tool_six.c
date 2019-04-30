/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:50:12 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/15 14:37:48 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_struct_clear(void)
{
	int			i;

	i = 0;
	if ((g_f.src = ft_memalloc(100000)) == NULL)
	{
		ft_printf("%file~ERROR: malloc\n", g_f.fd);
		return (-1);
	}
	ft_bzero(g_f.src, 100000);
	g_f.plato_x = 0;
	g_f.plato_y = 0;
	g_f.plato_last = 0;
	g_f.piece_x = 0;
	g_f.piece_y = 0;
	g_f.plato = NULL;
	g_f.piece = NULL;
	while (i != 200)
	{
		g_var_store[i].i = -1;
		i++;
	}
	return (0);
}
