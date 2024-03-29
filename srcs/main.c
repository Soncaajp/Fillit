/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:05:56 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/19 12:06:50 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int					main(int argc, char **argv)
{
	char			buffer[547];
	char			*input;
	int				amount;
	t_tetriminos	*objects;
	t_map			map;

	buffer[read(open(argv[1], O_RDONLY), buffer, 546)] = '\0';
	input = ft_strdup(buffer);
	amount = amount_tetriminos(input);
	if (validation(input, amount) && argc == 2)
	{
		objects = fill_objects(input, amount);
		if (!objects)
			return (0);
		map.amount = amount;
		map.size = minimal_map_size(amount);
		get_solution(objects, &map);
		write(1, map.solution, (map.width - 1));
		free(objects);
	}
	else
		ft_putstr("error\n");
	free(input);
	return (0);
}
