/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:30:19 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 14:48:07 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_parse_flags(t_format *fmt, t_holder *holder)
{
	char	*temp;

	if (!holder->prefix)
		holder->prefix = ft_strdup("");
	while (ft_strchr(HOLDER_ALL_FLAGS, fmt->format[fmt->i]))
	{
		if (fmt->format[fmt->i] == HOLDER_JUSTIFY)
			holder->left_justify = 1;
		if (ft_strchr(HOLDER_PREFIX, fmt->format[fmt->i]))
		{
			temp = holder->prefix;
			holder->prefix = ft_append_chr(temp, fmt->format[fmt->i]);
			free(temp);
		}
		if (fmt->format[fmt->i] == HOLDER_PAD)
			holder->padding = HOLDER_PAD;
		fmt->i++;
	}
}
