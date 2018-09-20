/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:22:20 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/20 10:52:30 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	**ft_get_array(int row, int cols, int fd, int skip)
{
	char	**arr;
	char	*line;
	int		i;

	i = 0;
	arr = (char **)ft_memalloc(sizeof(char *) * (row + 1));
	while (i < row)
	{
		arr[i] = (char *)malloc(sizeof(char) * (cols + 1));
		get_next_line(fd, &line);
		ft_strncpy(arr[i], &line[skip], cols);
		arr[i][cols] = '\0';
		free(line);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

t_input	ft_get_map(int fd)
{
	t_input	map_dim;
	char	**split;
	char	*line;
	int		read_ret;

	line = NULL;
	while (line == NULL && (read_ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != 'P')
		{
			free(line);
			line = NULL;
		}
	}
	if (line != NULL)
	{
		split = ft_strsplit(line, ' ');
		map_dim.row = atoi(split[1]);
		map_dim.cols = atoi(split[2]);
		free(line);
		get_next_line(fd, &line);
		free(line);
		map_dim.array = ft_get_array(map_dim.row, map_dim.cols, fd, 4);
		ft_free(split);
	}
	return (map_dim);
}

t_input	ft_get_piece(int fd)
{
	t_input	piece_dim;
	char	**split;
	char	*line;

	if (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		piece_dim.row = atoi(split[1]);
		piece_dim.cols = atoi(split[2]);
		free(line);
		piece_dim.array = ft_get_array(piece_dim.row, piece_dim.cols, fd, 0);
		ft_free(split);
	}
	return (piece_dim);
}

int		ft_get_player_num(int fd)
{
	int		player_num;
	char	*line;
	int		read_ret;

	line = NULL;
	while (line == NULL && (read_ret = get_next_line(fd, &line)) > 0 )
	{
		if (line[0] != '$')
		{
			free(line);
			line = NULL;
		}
	}
	player_num = ft_atoi(&line[10]);
	free(line);
	return (player_num);
}

void	ft_print_array(char **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putendl((const char *)array[i]);
		i++;
	}
}
