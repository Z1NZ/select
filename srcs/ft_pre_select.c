/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 04:34:47 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 17:28:39 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_pre_select(void)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	if (G(arg)[G(curr_arg)])
	{
		if (strncmp(G(arg)[G(curr_arg)], HIGHLIGHT_PRE, 3) != 0)
		{
			while (G(select)[i])
				i++;
			G(select)[i] = ft_strdup(G(arg)[G(curr_arg)]);
			tmp = ft_strjoin(HIGHLIGHT_PRE, G(arg)[G(curr_arg)]);
			tmp2 = G(arg)[G(curr_arg)];
			G(arg)[G(curr_arg)] = ft_strjoin(tmp, HIGHLIGHT_POST);
			ft_memdel((void **)&tmp);
			ft_memdel((void **)&tmp2);
		}
		else
			ft_unselect();
		ft_putscreen(G(curr_arg));
	}
}
