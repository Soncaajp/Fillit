/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:02:46 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/19 12:03:03 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	coordinates(t_tetriminos *object, t_map *map)
{
	int		i;
	int		x;
	int		y;

	x = object->position % (map->size + 1);
	y = (object->position + 1) / (map->size + 1);
	i = -1;
	while (++i < 4)
		object->coordination[i] = (map->size * (object->y[i] + y))
			+ (object->x[i] + x) + (object->y[i] + y);
}

static int	write(t_tetriminos *object, t_map *map)
{
	int		i;

	i = -1;
	while (++i < 4)
		map->solution[object->coordination[i]] = 65 + object->number;
	return (1);
}

int			free_place(t_tetriminos *object, t_map *map)
{
	int		i;

	i = -1;
	coordinates(object, map);
	while (++i < 4)
		if ((object->coordination[i] > map->width) ||
				(map->solution[object->coordination[i]] != '.'))
			return (0);
	return (write(object, map));
}
