/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 16:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/05/08 09:24:24 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_remove(void)
{
	char	*tmp;
	int		i;

	if ((G(curr_max) > 1))
	{
		i = G(curr_arg);
		if (strncmp(G(arg)[G(curr_arg)], HIGHLIGHT_PRE, 3) == 0)
			ft_unselect();
		while (G(arg)[i + 1])
		{
			tmp = G(arg)[i];
			G(arg)[i] = G(arg)[i + 1];
			G(arg)[i + 1] = tmp;
			i++;
		}
		ft_memdel((void **)&G(arg)[i]);
		G(curr_max)--;
		if (G(curr_arg) == G(curr_max))
			G(curr_arg)--;
		G(res) = tgetstr("cl", NULL);
		tputs(G(res), 0, my_outc);
		ft_resize(0);
	}
	if (G(curr_max) == 1)
		ft_return(0);
}
