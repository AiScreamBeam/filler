/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:41:14 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/19 15:14:38 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		g_dist;
t_input	g_best;

int		ft_place_help(t_cords mod, t_input map, t_input piece, char player_char)
{
	if (mod.r >= 0 && mod.c >= 0)
	{
		if (ft_valid(piece, mod, map, player_char) == 1)
		{
			if (ft_get_distance(piece, mod, map, player_char)
			< g_dist || g_dist == -1)
			{
				g_dist = ft_get_distance(piece, mod, map, player_char);
				g_best.row = mod.r;
				g_best.cols = mod.c;
			}
		}
	}
	return (g_dist);
}

void	ft_put_piece(void)
{
/*	if (g_dist == -1)
	{
		ft_putendl("0 0");
	}
	else
	{*/
		ft_putnbr(g_best.row);
		ft_putstr(" ");
		ft_putnbr(g_best.cols);
		ft_putstr("\n");
	//}
}

int		ft_place_piece(t_input map, t_input piece, char player_char)
{
	int		i;
	int		j;
	t_cords trim;
	t_cords mod;

	i = 0;
	g_dist = -1;
	trim.c = ft_cols_check(piece);
	trim.r = ft_row_check(piece);
	while (i < map.row)
	{
		j = 0;
		while (j < map.cols)
		{
			mod.r = i - trim.r;
			mod.c = j - trim.c;
			g_dist = ft_place_help(mod, map, piece, player_char);
			j++;
		}
		i++;
	}
	ft_put_piece();
	return (g_dist);
}

int		ft_get_distance(t_input piece, t_cords cords, t_input map, char play_c)
{
	int		i;
	int		j;
	t_input	calc;
	int		disti;

	i = 0;
	disti = -1;
	while (i < piece.row)
	{
		j = 0;
		while (j++ < piece.cols)
		{
			if (piece.array[i][j] == '*')
			{
				calc.row = ((map.row / 2) - (i + cords.r));
				calc.row *= calc.row;
				calc.cols = ((map.cols / 2) - (j + cords.c));
				calc.cols *= calc.cols;
				if (calc.row + calc.cols > disti || disti == -1)
					disti = calc.row + calc.cols;
			}
		}
		i++;
	}
	return (disti);
}
