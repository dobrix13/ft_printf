/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:00:21 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 19:05:43 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prefix_ux(t_holder *holder)
{
	char	*temp;

	temp = holder->argument;
	if (ft_strchr(holder->prefix, '#'))
	{
		if (holder->conversion == 'x')
			holder->argument = ft_strjoin(PTR_HEX_L_PREFIX, temp);
		if (holder->conversion == 'X')
			holder->argument = ft_strjoin(HEX_U_PREFIX, temp);
		if (holder->conversion == 'o')
			holder->argument = ft_strjoin(OCT_PREFIX, temp);
		free(temp);
	}
}


void	ft_add_prefix(t_holder	*holder, int sign)
{
	int	len;

	len = (int)ft_strlen(holder->argument);
	if (holder->conversion == 'd' || holder->conversion == 'i')
	{
		len += 1;
		if (ft_strchr(holder->prefix, PLUS) && sign == 1)
			ft_fill_left_pad(&holder->argument, PLUS, len);
		else if (ft_strchr(holder->prefix, SPACE) && sign == 1)
			ft_fill_left_pad(&holder->argument, SPACE, len);
		else if (sign == -1)
			ft_fill_left_pad(&holder->argument, MINUS, len);
	}
	else if (holder->conversion == 'x' || h->conversion == 'X' \
			|| holder->conversion == 'o')
		ft_prefix_ux(h);
}
