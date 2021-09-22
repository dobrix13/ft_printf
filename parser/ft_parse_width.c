/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:31:29 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 14:48:07 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_parse_width(t_format *fmt, t_holder *holder)
{
	int	width;

	width = holder->width;
	if (fmt->format[fmt->i] == HOLDER_STAR)
	{
		width = (int)va_arg(fmt->ap, int);
		if (width < 0)
		{
			holder->left_justify = 1;
			width *= -1;
		}
		fmt->i++;
	}
	else if (ft_isdigit(fmt->format[fmt->i]))
	{
		width = 0;
		while (ft_isdigit(fmt->format[fmt->i]))
		{
			width = (width * 10) + (fmt->format[fmt->i] - '0');
			fmt->i++;
		}
	}
	holder->width = width;
}
