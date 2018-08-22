/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putscreen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:56:46 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 17:27:37 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <unistd.h>

static void		ft_putscreen_f_ko(int i, int j)
{
	if (i == j)
	{
		ft_putstr_fd(tgetstr("us", NULL), G(fd));
		ft_putstr_fd(G(arg)[i], G(fd));
		ft_putstr_fd(tgetstr("ue", NULL), G(fd));
	}
	else
		ft_putstr_fd(G(arg)[i], G(fd));
}

static void		ft_put_s_f_ok(int i, int j)
{
	ft_putstr_fd(GREEN, G(fd));
	if (i == j)
	{
		ft_putstr_fd(tgetstr("us", NULL), G(fd));
		ft_putstr_fd(G(arg)[i], G(fd));
		ft_putstr_fd(tgetstr("ue", NULL), G(fd));
	}
	else
		ft_putstr_fd(G(arg)[i], G(fd));
	ft_putstr_fd(WHITE, G(fd));
}

static void		ft_whiler_arg(int i, int n, int co, int j)
{
	while (G(arg[i]))
	{
		if (access(G(arg)[i], F_OK) == 0)
			ft_put_s_f_ok(i, j);
		else
			ft_putscreen_f_ko(i, j);
		if (n >= G(nb_line) && (int)(G(max) * co) < G(nb_co))
		{
			n = 0;
			co++;
		}
		if (i < G(nb_line))
			tputs(tgoto(G(res), 0, i), 1, my_outc);
		else
		{
			tputs(tgoto(G(res), G(max) * co, n), 1, my_outc);
			n++;
		}
		i++;
	}
}

void			ft_putscreen(int j)
{
	int i;
	int n;
	int co;
	int comp;

	co = 1;
	i = 1;
	n = 0;
	comp = (G(nb_co) / G(max)) * G(nb_line);
	tputs(tgoto(G(res), 0, 0), 1, my_outc);
	if (G(curr_max) >= comp)
	{
		ft_putstr_fd(RED, G(fd));
		ft_putstr_fd("windows to small", G(fd));
		ft_putstr_fd(WHITE, G(fd));
	}
	else
		ft_whiler_arg(i, n, co, j);
}
