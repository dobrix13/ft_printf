/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:08:23 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 00:05:53 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_convert_c(t_format *fmt, t_holder *holder)
{
	char	c;

	c = (wint_t)va_arg(fmt->ap, wint_t);
	if (!holder->width)
		holder->width += 1;
	holder->argument = (char *)malloc(holder->width * sizeof(char));
	if (!holder->argument)
		return ;
	ft_memset(holder->argument, SPACE, holder->width);
	if (holder->left_justify == 1)
		holder->argument[0] = c;
	else
		holder->argument[holder->width - 1] = c;
	holder->len = holder->width;
}
