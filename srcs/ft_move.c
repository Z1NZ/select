/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 04:32:05 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 17:40:51 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_move_next(void)
{
	if (G(curr_arg) < G(curr_max) - 1)
		G(curr_arg)++;
	else
		G(curr_arg) = 1;
}

static void	ft_move_back(void)
{
	if (G(curr_arg) > 1)
		G(curr_arg)--;
	else
		G(curr_arg) = G(curr_max) - 1;
}

static void	ft_move_left(void)
{
	if (G(curr_arg) > G(nb_line))
		G(curr_arg) -= G(nb_line);
	else
		G(curr_arg) = 1;
}

static void	ft_move_right(void)
{
	if (G(curr_arg) + G(nb_line) <= G(curr_max))
		G(curr_arg) += G(nb_line);
	else
		G(curr_arg) = G(curr_max) - 1;
}

void		ft_move(int i)
{
	ft_size_term();
	if (i == NEXT)
		ft_move_next();
	else if (i == BACK)
		ft_move_back();
	else if (i == M_LEFT)
		ft_move_left();
	else if (i == M_RIGHT)
		ft_move_right();
	ft_putscreen(G(curr_arg));
}
