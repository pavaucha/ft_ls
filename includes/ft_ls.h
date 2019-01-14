/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:00:12 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/12 13:57:25 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/includes/ft_printf.h"
# include <sys/xattr.h>

typedef struct		s_flagsls
{
	int				l;
	int				r;
	int				r2;
	int				a;
	int				t;
	int				wadi;
}					t_flagsls;

typedef struct		s_ls
{
	char			*str;
	DIR				*dir;
	struct dirent	*read;
	struct stat		fd;
	struct s_ls		*next;
	struct s_ls		*before;
	int				type;
}					t_ls;

typedef struct		s_llist
{
	intmax_t		maj;
	intmax_t		min;
	char			perm[12];
	char			*str;
	struct stat		fd;
	intmax_t		octet;
	char			*str_o;
	struct s_llist	*next;
	struct s_llist	*before;
	char			*uid;
	char			*grp;
	char			*ctime;
	char			*link;
}					t_llist;

void				ft_change_list(t_ls *list, t_flagsls flags);
t_llist				*ft_str_uid_grp(t_llist *list);
t_llist				*ft_p_octet(t_llist *list, char *str);
t_ls				*ft_swap_t_char_list(t_ls *list,
					t_ls *begin_list, t_flagsls flags, char *tmp);
t_ls				*ft_swap_char_list(t_ls *list,
					t_ls *begin_list, t_flagsls flags, char *tmp);
t_flagsls			ft_initialize_flags(void);
t_flagsls			ft_assign(t_flagsls flags, char **str, int i, int j);
t_llist				*ft_free_llist(t_llist *list);
t_ls				*ft_free_list(t_ls *list);
char				*ft_cut_time(char *str);
char				*ft_years(char *str);
int					ft_strcmp_t(char *str, char *dst, char *open);
char				**ft_sort_t(char **str,
					int nb, t_flagsls flags, char *open);
t_llist				*ft_block_octet(t_llist *list, char *open);
t_llist				*ft_take_link(t_llist *list);
t_llist				*ft_take_time(t_llist *list, char *open);
int					ft_nb_list(t_llist *list);
void				ft_padding_str(t_llist *list, char *open, int f);
int					ft_cmp_imax(intmax_t nb);
char				*ft_strnew_c(int size, char c);
char				*ft_uitoa(intmax_t nb);
void				ft_keep_l(char **str, char *open, int f);
int					ft_dstrlen(char **str);
t_ls				*ft_aff_del_file(t_ls *list, t_flagsls flags);
void				ft_start_recursive(t_flagsls flags, int nba, char **str);
t_ls				*ft_list_initialize(char *str, t_ls *next, t_ls *before);
t_llist				*ft_list_l_initialize(char *str,
					t_llist *next, t_llist *before);
void				ft_recursive_ls(t_flagsls flags, t_ls list, int i);
char				**ft_ascii(char **str, int nb, t_flagsls flags);
void				ft_sort_affiche(char *str, t_flagsls flags);
t_ls				*ft_del_list(t_ls *list);
char				*ft_cut_slh(char *str);
int					ft_recu_a(char *str);

#endif
