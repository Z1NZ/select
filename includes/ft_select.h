/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:40:18 by srabah            #+#    #+#             */
/*   Updated: 2015/03/19 20:46:12 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/libft/includes/libft.h"
# include <curses.h>
# include <unistd.h>
# include <term.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <fcntl.h>

typedef struct			s_global
{
	struct termios		term;
	struct termios		old;
	char				**arg;
	char				**select;
	char				*res;
	char				*ttyname;
	int					curr_arg;
	int					curr_max;
	int					fd;
	size_t				max;
	int					nb_line;
	int					nb_co;
}						t_global;

# define UNDERLINED_PRE		"\033[4m"
# define UNDERLINED_POST	"\033[0m"
# define HIGHLIGHT_PRE		"\033[7m"
# define HIGHLIGHT_POST		"\033[m"
# define RED				"\033[1;31m"
# define GREEN				"\033[1;32m"
# define WHITE				"\033[0m"
# define UP					4283163
# define DOWN				4348699
# define RIGHT				4414235
# define LEFT				4479771
# define NEXT				1
# define BACK				2
# define M_LEFT				3
# define M_RIGHT			4
# define SPACE				32
# define RETURN				10
# define ESC				27
# define BACKSPACE			127
# define DELETE				2117294875
# define G(x)				g()->x

void					ft_display_init(int i);
t_global				*g(void);
void					ft_move(int i);
void					ft_pre_select(void);
void					ft_putscreen(int j);
void					ft_putspace(int nb);
void					ft_return(int t);
void					ft_unselect(void);
void					ft_unselect_form_tab(int i);
int						my_outc(int c);
void					ft_signal();
void					ft_resize(int i);
void					ft_remove(void);
void					ft_size_term(void);
void					ft_clear(int i);
void					ft_handler(int n);
void					ft_size_term(void);
void					ft_resize(int i);
#endif
