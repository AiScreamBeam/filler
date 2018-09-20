/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:15:47 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/20 10:56:56 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/filler.h"

int		main(void)
{
	int		fd;
	int		player_nr;
	int		res;
	t_input	map;
	t_input	piece;

//	map.trig = 0;
	fd = 0;
	player_nr = ft_get_player_num(fd);
	while (1)
	{
//		ft_putendl_fd("entering get_map", 2);
		map = ft_get_map(fd);
//		ft_putendl_fd("passed get_map", 2);
		piece = ft_get_piece(fd);
//		ft_putendl_fd("exited get_piece", 2);
		if (player_nr == 1)
		{
			res = ft_place_piece(map, piece, 'O');
		}
		else
			res = ft_place_piece(map, piece, 'X');
		ft_free(map.array);
		ft_free(piece.array);
//		if (res == -1)
//			ft_putendl("0 0");
	}
//	ft_putendl("0 0");
	return (0);
}
