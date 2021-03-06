/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:34:26 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/06 14:53:52 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_ucharlen(const int c)
{
	if (c <= 255)
		return (1);
	if (c < 2048)
		return (2);
	if (c < 65536)
		return (3);
	if (c < 2097152)
		return (4);
	return (-1);
}
