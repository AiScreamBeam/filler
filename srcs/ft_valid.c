/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:53:06 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/20 10:39:15 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		g_i;
int		g_j;
int		g_overlap;

int		ft_cols_check(t_input piece)
{
	int		i;
	int		j;
	int		counter;
	int		result;

	i = 0;
	result = piece.cols;
	while (i < piece.row)
	{
		j = 0;
		counter = 0;
		while (j < piece.cols && piece.array[i][j] != '*')
		{
			if (piece.array[i][j] == '.')
				counter++;
			j++;
		}
		if (counter < result)
			result = counter;
		i++;
	}
	if (result == piece.cols)
		return (0);
	return (result);
}

int		ft_row_check(t_input piece)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (i < piece.row)
	{
		if (ft_strchr(piece.array[i], '*') != NULL)
		{
			//return (counter);
			break ;
		}
		else
			counter++;
		i++;
	}
	//ft_putstr_fd("the piece row: ", 2);
	//ft_putnbr_fd(counter, 2);
	//ft_putstr_fd("\n", 2);
	return (counter);
}

int		ft_valid(t_input piece, t_cords cord, t_input map, char p)
{
	g_i = -1;
	g_overlap = 0;
	if (cord.r + piece.row > map.row)
		return (-1);
	if (cord.c + piece.cols > map.cols)
		return (-1);
	while (++g_i < piece.row)
	{
		g_j = -1;
		while (++g_j < piece.cols)
		{
			if (piece.array[g_i][g_j] == '*')
			{
				if (g_i + cord.r < map.row && g_j + cord.c < map.cols)
				{
					if (map.array[cord.r + g_i][cord.c + g_j] != '.')
					{
						if (ft_up(map.array[cord.r + g_i][cord.c + g_j]) == p)
							g_overlap++;
						else
							return (-1);
					}
				}
				else
					return (-1);
			}
		}
	}
	return (g_overlap);
}
