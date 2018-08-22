/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unselect_form_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 04:32:47 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 17:01:06 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_unselect_form_tab(int i)
{
	char *tmp;

	while (G(select)[i + 1] != NULL)
	{
		tmp = G(select)[i];
		G(select)[i] = G(select)[i + 1];
		G(select)[i + 1] = tmp;
		i++;
	}
	ft_memdel((void **)&G(select)[i]);
}
