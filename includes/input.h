/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:01:55 by mschempe          #+#    #+#             */
/*   Updated: 2018/09/18 12:02:40 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef struct	s_input
{
	char	**array;
	int		row;
	int		cols;
}				t_input;

typedef struct	s_cords
{
	int		r;
	int		c;
}				t_cords;

#endif
