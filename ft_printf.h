/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:55:25 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 01:13:04 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <wchar.h>

# include "libft/libft.h"

# define HOLDER_CONVERSION "cspdiuxX%o"
# define HOLDER_ALL "-0# +123456789*"
# define HOLDER_ALL_FLAGS "-0# +"
# define HOLDER_JUSTIFY '-'
# define HOLDER_PREFIX "# +"
# define HOLDER_PAD '0'
# define HOLDER_PRECISION '.'
# define HOLDER_STAR '*'

# define HEXADECIMAL_U_BASE "0123456789ABCDEF"
# define DECIMAL_BASE "0123456789"
# define HEXADECIMAL_L_BASE "0123456789abcdef"
# define OCTAL_BASE "01234567"
# define PTR_HEX_L_PREFIX "0x"
# define HEX_U_PREFIX "0X"
# define OCT_PREFIX "0"
# define MINUS '-'
# define PLUS '+'
# define SPACE ' '

typedef struct s_format
{
	const char	*format;
	va_list		ap;
	size_t		i;
	size_t		len;
}			t_format;

typedef struct s_holder
{
	size_t	len;
	char	*prefix;
	char	*argument;
	char	padding;
	char	conversion;
	int		left_justify;
	int		width;
	int		precision;
}			t_holder;
/*
**	print
*/
int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list argument_parameter);
/*
**	initialize
*/
t_format	*ft_initialize_format(const char *format, va_list ap);
t_holder	*ft_initialize_holder(void);
void		ft_placeholder(t_format *tmp);
/*
**	parser
*/
void		*ft_parse(t_format *fmt, t_holder *holder);
void		ft_parse_width(t_format *fmt, t_holder *holder);
void		ft_parse_precision(t_format *fmt, t_holder *holder);
void		ft_parse_flags(t_format *fmt, t_holder *holder);
void		ft_parse_conversion(t_format *fmt, t_holder *holder);
/*
**	type conversion
*/
void		ft_type_conversion(t_format *fmt, t_holder *holder);
void		ft_convert_c(t_format *fmt, t_holder *holder);
void		ft_convert_s(t_format *fmt, t_holder *holder);
void		ft_convert_p(t_format *fmt, t_holder *holder);
void		ft_convert_d_i(t_format *fmt, t_holder *holder);
void		ft_convert_ux(t_format *fmt, t_holder *holder, char *base);
void		ft_convert_prct(t_holder *holder);
void		ft_add_prefix(t_holder	*holder, int sign);
/*
**	tools
*/
char		*ft_u_itoa_base(unsigned long nbr, char *base);
char		*ft_append_chr(char const *s, char const c);
char		*ft_set_null(t_holder *holder);
void		ft_fill_left_pad(char **src, char padding, int width);
void		ft_fill_right_pad(char **src, char padding, int width);

#endif
