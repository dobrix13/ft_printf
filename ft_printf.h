/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:55:25 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 13:54:04 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define	HOLDER_CONVERSION "cspdiuxX%o"
# define	HOLDER_ALL "-0# +123456789*"
# define	HOLDER_ALL_FLAGS "-0# +"
# define	HOLDER_JUSTIFY '-'
# define	HOLDER_PREFIX "# +"
# define	HOLDER_PAD '0'
# define	HOLDER_PRECISION '.'
# define	HOLDER_STAR '*'

# define	OCTAL_BASE "01234567"
# define	DECIMAL_BASE "0123456789"
# define	HEXADECIMAL_U_BASE "0123456789ABCDEF"
# define	HEXADECIMAL_L_BASE "0123456789abcdef"

# define	PTR_HEX_L_PREFIX "0x"
# define	HEX_U_PREFIX "0X"
# define	OCT_PREFIX "0"
# define	MINUS '-'
# define	PLUS '+'
# define	SPACE ' '

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

int	ft_vprintf(const char *format, va_list argument_parameter);

#endif
