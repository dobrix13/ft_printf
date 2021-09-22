/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:37:28 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 14:48:07 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_parse_conversion(t_format *fmt, t_holder *holder)
{
	if (!ft_strchr(HOLDER_ALL, fmt->format[fmt->i]) \
		&& ft_isprint(fmt->format[fmt->i]))
	{
		holder->conversion = fmt->format[fmt->i];
		fmt->i++;
	}
}
