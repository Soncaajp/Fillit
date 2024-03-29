/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:10:44 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/19 12:10:54 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_tetriminos{
	int				number;
	int				x[4];
	int				y[4];
	int				position;
	int				coordination[4];
}					t_tetriminos;

typedef struct		s_map{
	int				size;
	int				width;
	int				amount;
	char			solution[241];
}					t_map;

int					amount_tetriminos(char *input);
int					validation(char *input, int amount);

t_tetriminos		*fill_objects(char *input, int amount);

void				next_step(t_tetriminos *objects, t_map *map, int start);
int					next_position(t_tetriminos *object, t_map *map);

int					minimal_map_size(int amount);

int					free_place(t_tetriminos *object, t_map *map);

t_map				*get_solution(t_tetriminos *objects, t_map *map);

#endif
