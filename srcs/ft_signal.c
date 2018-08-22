/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 19:47:00 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 20:48:30 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <signal.h>

void	ft_clear(int i)
{
	int n;

	n = G(nb_line);
	(void)i;
	while (n--)
	{
		G(res) = tgetstr("dl", NULL);
		tputs(G(res), 0, my_outc);
		G(res) = tgetstr("up", NULL);
		tputs(G(res), 0, my_outc);
	}
	G(res) = tgetstr("cl", NULL);
	tputs(G(res), 0, my_outc);
	G(res) = tgetstr("ve", NULL);
	tputs(G(res), 0, my_outc);
	G(res) = tgetstr("rs", NULL);
	tputs(G(res), 0, my_outc);
	return ;
}

void	ft_handler(int n)
{
	char get_out[2];

	ft_clear(n);
	tcsetattr(0, TCSADRAIN, &G(old));
	signal (SIGTSTP, SIG_DFL);
	get_out[0] = G(old).c_cc[VSUSP];
	get_out[1] = '\0';
	ioctl(0, TIOCSTI, get_out);
	(void)n;
}

void	ft_size_term(void)
{
	struct winsize	win;

	ioctl(G(fd), TIOCGWINSZ, &win);
	G(nb_line) = win.ws_row;
	G(nb_co) = win.ws_col;
}

void	ft_resize(int i)
{
	(void)i;
	if (tcsetattr(0, TCSADRAIN, &G(term)) == -1)
		exit (-1);
	G(term).c_lflag &= ~(ICANON);
	G(term).c_lflag &= ~(ECHO);
	G(term).c_cc[VMIN] = 1;
	G(term).c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &G(term)) == -1)
		exit (-1);
	if ((G(res) = tgetstr("cl", NULL)) == NULL)
		exit (-1);
	tputs(G(res), 0, my_outc);
	if ((G(res) = tgetstr("vi", NULL)) == NULL)
		exit (-1);
	tputs(G(res), 0, my_outc);
	if ((G(res) = tgetstr("cm", NULL)) == NULL)
		exit (-1);
	ft_size_term();
	ft_putscreen(G(curr_arg));
}

void	ft_signal(void)
{
	int i;

	i = 0;
	signal(SIGCONT, ft_resize);
	signal(SIGWINCH, ft_resize);
	signal(SIGTSTP, ft_handler);
	while (i < 32)
	{
		if (i != SIGCONT && i != SIGWINCH && i != SIGTSTP)
			signal(i, ft_return);
		i++;
	}
}
