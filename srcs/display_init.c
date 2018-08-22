/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 18:26:10 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 19:38:14 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int		ft_init_term(void)
{
	if (tgetent(NULL, getenv("TERM")) == ERR)
		return (-1);
	if (tcgetattr(0, &G(term)) == -1)
		return (-1);
	if (tcgetattr(0, &G(old)) == -1)
		return (-1);
	G(term).c_lflag &= ~(ICANON);
	G(term).c_lflag &= ~(ECHO);
	G(term).c_cc[VMIN] = 1;
	G(term).c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &G(term)) == -1)
		return (-1);
	if ((G(res) = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(G(res), 0, my_outc);
	if ((G(res) = tgetstr("vi", NULL)) == NULL)
		return (-1);
	tputs(G(res), 0, my_outc);
	if ((G(res) = tgetstr("cm", NULL)) == NULL)
		return (-1);
	ft_size_term();
	ft_putscreen(G(curr_arg));
	return (1);
}

static void		ft_hub_move(int keycode)
{
	if (keycode == (DOWN) && (G(curr_max) > 1))
		ft_move(NEXT);
	if (keycode == UP && (G(curr_max) > 1))
		ft_move(BACK);
	if (keycode == LEFT)
		ft_move(M_LEFT);
	if (keycode == RIGHT)
		ft_move(M_RIGHT);
	if ((keycode == SPACE) && (G(curr_max) > 0))
	{
		ft_pre_select();
		ft_move(NEXT);
	}
}

void			ft_display_init(int i)
{
	char			buffer[10];
	int				keycode;

	keycode = i;
	if (ft_init_term() == -1)
		exit(-1);
	while (1)
	{
		ft_bzero(buffer, 10);
		read(0, buffer, 4);
		keycode = (buffer[3] << 24) + (buffer[2] << 16) +
			(buffer[1] << 8) + buffer[0];
		if (keycode == (DOWN) || keycode == UP || keycode == LEFT ||
				keycode == RIGHT || (keycode == SPACE))
			ft_hub_move(keycode);
		if ((keycode == BACKSPACE || keycode == DELETE) && G(curr_max) > 0)
			ft_remove();
		if (keycode == RETURN)
			break ;
		if (keycode == ESC)
			ft_return(0);
	}
	ft_return(1);
}
