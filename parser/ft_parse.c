/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:32:18 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 00:00:21 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_parse(t_format *fmt, t_holder *holder)
{
	ft_parse_flags(fmt, holder);
	ft_parse_width(fmt, holder);
	ft_parse_precision(fmt, holder);
	ft_parse_conversion(fmt, holder);
	if (!holder->conversion && (ft_strchr(HOLDER_ALL, fmt->format[fmt->i])))
		ft_parse(fmt, holder);
	return (holder);
}
