/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:19:45 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/18 12:03:33 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "input.h"
# include <fcntl.h>

char	**ft_get_array(int row, int cols, int fd, int skip);
t_input	ft_get_map(int fd);
t_input	ft_get_piece(int fd);
int		ft_get_player_num(int fd);
void	ft_print_array(char **array);
void	ft_free(char **matrix);
int		ft_cols_check(t_input piece);
int		ft_row_check(t_input piece);
int		ft_valid(t_input piece, t_cords cord, t_input map, char p);
int		ft_place_piece(t_input map, t_input piece, char player_char);
int		ft_get_distance(t_input piece, t_cords cords, t_input map, char play_c);

#endif
