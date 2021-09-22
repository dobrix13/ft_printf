/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:47:24 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 01:01:40 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_convert_d_i_width(t_holder *holder, int sign);

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

static void	ft_convert_d_i_width(t_holder *holder, int sign)
{
	if (holder->left_justify)
	{
		ft_add_prefix(holder, sign);
		ft_fill_right_pad(&holder->argument, ' ', holder->width);
	}
	else
	{
		if (holder->padding == ' ')
		{
			ft_add_prefix(holder, sign);
			ft_fill_left_pad(&holder->argument, holder->padding, holder->width);
		}
		else if (holder->padding == '0')
		{
			if (sign < 0 || ft_strchr(holder->prefix, ' ') || \
				ft_strchr(holder->prefix, '+'))
				ft_fill_left_pad(&holder->argument, holder->padding, \
				holder->width - 1);
			else
				ft_fill_left_pad(&holder->argument, holder->padding, \
				holder->width);
			ft_add_prefix(holder, sign);
		}
	}
}
