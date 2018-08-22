/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 04:35:37 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 20:46:00 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_return(int t)
{
	int n;

	n = G(nb_line);
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
	if (tcsetattr(0, TCSADRAIN, &G(old)) == -1)
		exit(-1);
	n = 0;
	if (t == 1)
		while (g()->select[n])
		{
			ft_putstr(G(select)[n]);
			ft_putstr(" ");
			n++;
		}
	exit(1);
}
