/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unselect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 04:34:05 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 17:01:26 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_unselect(void)
{
	char	*tmp;
	char	*tmp_s;
	int		i;

	i = 0;
	tmp = (G(arg)[G(curr_arg)]) + 4;
	while (G(select)[i])
	{
		tmp_s = ft_strjoin(G(select)[i], HIGHLIGHT_POST);
		if (ft_strcmp(tmp, tmp_s) == 0)
			break ;
		ft_memdel((void**)&tmp_s);
		i++;
	}
	if (G(select)[i])
	{
		tmp = G(arg)[G(curr_arg)];
		G(arg)[G(curr_arg)] = ft_strdup(G(select)[i]);
		ft_memdel((void**)&tmp);
		ft_unselect_form_tab(i);
	}
}
