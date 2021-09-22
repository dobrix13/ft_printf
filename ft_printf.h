/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:55:25 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 13:23:28 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

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
