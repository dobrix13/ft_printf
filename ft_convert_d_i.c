/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:47:24 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 20:13:10 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_d_i(t_format *fmt, t_holder *holder)
{
	int			sign;
	long int	num;

	sign = 1;
	num = (int)va_arg(fmt->ap, int);
	if (num < 0)
		sign *= -1;
	holder->argument = ft_u_itoa_base(sign * num, DECIMAL_BASE);
	if (holder->precision > -1)
	{
		if (!holder->precision && num == 0)
		{
			free(holder->argument);
			holder->argument = ft_strdup("");
		}
		ft_fill_left_pad(&holder->argument, '0', holder->precision);
		holder->padding = ' ';
	}
	ft_convert_d_i_width(holder, sign);
	holder->len = ft_strlen(holder->argument);
}