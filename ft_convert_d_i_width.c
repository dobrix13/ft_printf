/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:16:56 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 20:22:23 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
				ft_fill_left_pad(&holder->argument, holder->padding, holder->width - 1);
			else
				ft_fill_left_pad(&holder->argument, holder->padding, holder->width);
			ft_add_prefix(holder, sign);
		}
	}
}
