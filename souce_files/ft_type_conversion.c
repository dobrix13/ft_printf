/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:39:40 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 00:05:53 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_type_conversion(t_format *fmt, t_holder *holder)
{	
	if (holder->conversion == 'c')
		ft_convert_c(fmt, holder);
	else if (holder->conversion == 's')
		ft_convert_s(fmt, holder);
	else if (holder->conversion == 'p')
		ft_convert_p(fmt, holder);
	else if (holder->conversion == 'd' || holder->conversion == 'i')
		ft_convert_d_i(fmt, holder);
	else if (holder->conversion == 'u')
		ft_convert_ux(fmt, holder, DECIMAL_BASE);
	else if (holder->conversion == 'x')
		ft_convert_ux(fmt, holder, HEXADECIMAL_L_BASE);
	else if (holder->conversion == 'X')
		ft_convert_ux(fmt, holder, HEXADECIMAL_U_BASE);
	else if (holder->conversion == 'o')
		ft_convert_ux(fmt, holder, OCTAL_BASE);
	else
		ft_convert_prct(holder);
}
