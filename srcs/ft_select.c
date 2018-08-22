/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 19:37:43 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 20:46:20 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		init_start(int i)
{
	G(arg)[i] = NULL;
	G(curr_arg) = 1;
	G(select) = (char**)ft_memalloc(sizeof(char*) * G(curr_max));
	G(fd) = open(ttyname(STDIN_FILENO), O_WRONLY);
	i = 1;
	G(max) = 0;
	while (G(arg[i]))
	{
		if (G(max) < ft_strlen(G(arg[i])))
			G(max) = ft_strlen(G(arg[i]));
		i++;
	}
	G(max) += 3;
}

t_global		*g(void)
{
	static t_global *sg = NULL;

	if (!sg)
		sg = malloc(sizeof(t_global));
	return (sg);
}

int				main(int argc, char *argv[], char **env)
{
	int i;

	i = 0;
	if (argc > 1 && *env != NULL)
	{
		G(curr_max) = argc;
		G(arg) = (char**)malloc(sizeof(char*) * argc);
		while (argv[i])
		{
			G(arg)[i] = ft_strdup(argv[i]);
			i++;
		}
		init_start(i);
		ft_signal();
		ft_display_init(1);
	}
	else
		ft_printf("%s", "ERROR ==> this programme need argument and env\n");
	return (0);
}
