/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:48:52 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 00:05:53 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_convert_ux(t_format *fmt, t_holder *holder, char *base)
{
	unsigned int	nbr;
	char			*number;

	number = NULL;
	nbr = (unsigned int)(va_arg(fmt->ap, unsigned int));
	number = ft_u_itoa_base((unsigned long)nbr, base);
	holder->argument = ft_strdup(number);
	free(number);
	if (holder->precision > -1)
	{
		if (!holder->precision && nbr == 0)
		{
			free(holder->argument);
			holder->argument = ft_strdup("");
		}
		ft_fill_left_pad(&holder->argument, '0', holder->precision);
		holder->padding = ' ';
	}
	if (nbr)
		ft_add_prefix(holder, 0);
	if (!holder->left_justify)
		ft_fill_left_pad(&holder->argument, holder->padding, holder->width);
	else
		ft_fill_right_pad(&holder->argument, ' ', holder->width);
	holder->len = ft_strlen(holder->argument);
}
