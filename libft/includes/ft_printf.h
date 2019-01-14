/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:00:24 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 14:27:38 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include <wchar.h>

typedef	struct	s_flags
{
	int		pourc;
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		intpre;
	int		intwidth;
	int		hh;
	int		h;
	int		l;
	int		ll;
	int		j;
	int		z;
}				t_flags;

void			ft_start_printf(t_flags flags, const char *format,
				va_list ap, int count[2]);
int				ft_nullstr(t_flags flags, int count);
int				ft_stock_zflags(t_flags flags, char c, int count);
int				ft_count_unicode(wint_t stock);
int				ft_affiche_bc(wint_t stock, t_flags flags);
int				ft_affiche_bs(wchar_t *str, t_flags flags);
t_flags			ft_change_zflags(t_flags flags, char c);
int				ft_affiche_c(int stock, t_flags flags);
int				ft_affiche_s(char *str, t_flags flags);
int				ft_champ(const char *format);
int				ft_stock_zero(int stock, t_flags flags, char c);
int				ft_space(t_flags flags);
int				ft_plus(t_flags flags, intmax_t stock);
int				ft_precision(t_flags flags);
int				ft_champ_minimum(t_flags flags);
t_flags			ft_change_flags(char c, uintmax_t stock,
				t_flags flags, int base);
t_flags			ft_change_flags_d(intmax_t stock, t_flags flags);
int				ft_affiche_d(intmax_t stock, t_flags flags);
int				ft_affiche(uintmax_t stock, t_flags flags, char c, int base);
int				ft_affiche_p(uintmax_t stock, t_flags flags, char c);
int				ft_strlen_unicode(wchar_t *str);
int				ft_putchar_unicode(wint_t stock, t_flags flags);
int				ft_affiche_pourc(const char *format, t_flags flags);
int				ft_printf(const char *format, ...);
int				ft_start_flags(const char *format, char c,
				t_flags flags, va_list ap);
int				s_printf(t_flags flags, va_list ap, char c);
int				d_printf(t_flags flags, va_list ap, char c);
int				c_printf(t_flags flags, va_list ap, char c);
int				p_printf(t_flags flags, va_list ap, char c);
int				o_printf(t_flags flags, va_list ap, char c);
void			ft_putnbr_hexa(uintmax_t i, int base, char c);
void			ft_putnbr_hecto(uintmax_t i, int base);
int				u_printf(t_flags flags, va_list ap, char c);
void			ft_putunsigned_int(uintmax_t i);
int				x_printf(t_flags flags, va_list ap, char c);
t_flags			ft_initialise_struct(t_flags flags);
t_flags			ft_stock_flags(const char *format);
intmax_t		ft_size_modification(t_flags flags, va_list ap);
void			ft_putnbr_max(intmax_t i);
t_flags			ft_found_flags(const char *format, t_flags flags);
int				ft_evolution_i(const char *format);
t_flags			ft_sflags(const char *format, t_flags flags);
t_flags			ft_precha(const char *format, t_flags flags);
t_flags			ft_fflags(const char *format, t_flags flags);
uintmax_t		ft_usize_modif(t_flags flags, va_list ap);
void			ft_put_type(uintmax_t stock, char c);
int				ft_count_i(const char *format);
#endif
