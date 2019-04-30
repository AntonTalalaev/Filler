/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:23:41 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/15 17:49:33 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_input
{
	char			*src;
	char			p_char;
	int				plato_x;
	int				plato_y;
	int				plato_last;
	int				piece_x;
	int				piece_y;
	int				piece_width;
	int				piece_hight;
	char			*plato;
	char			*piece;
	int				up;
	int				down;
	int				left;
	int				right;
	int				fd;
}				t_input;

typedef struct	s_store
{
	int				i;
	int				up;
	int				down;
	int				left;
	int				right;
	int				len_to_border;
	int				touch;
	int				enemy_direction;
}				t_store;

# define CHAR_X g_f.plato[i] == 'x' || g_f.plato[i] == 'X'
# define CHAR_O g_f.plato[i] == 'o' || g_f.plato[i] == 'O'
# define CHAR CHAR_X || CHAR_O
# define PLATO CHAR || g_f.plato[i] == '.'
# define CHAR_PL g_f.plato[i] == g_f.p_char || g_f.plato[i] == g_f.p_char + 32
# define CHAR_ENEMY (CHAR) && !(CHAR_PL)
# define CHECK_ENEMY_HIGH g_f.plato_y / 10
# define CHECK_ENEMY_LEN g_f.plato_x / 10

int				ft_piece_cheker(int i, int a, int count);
void			ft_piece_adder(int i);
void			ft_get_xy(void);
void			ft_get_input(void);
int				ft_get_output(void);
int				ft_struct_clear(void);
void			ft_border_update(int tmp);
int				ft_answer_touch(void);
void			ft_border_search(void);
void			ft_count_store(int i);
int				ft_new_turn(void);
int				ft_get_src(void);
int				ft_count_store_new_var(int i);
void			ft_count_store_border_check(int i, int a);
void			ft_dest_enemy_left_right(int i, int a);
void			ft_dest_enemy_up_down(int i, int a);
void			ft_dest_enemy(int i, int a);

extern	t_input		g_f;
extern	t_store		g_var_store[201];

#endif
