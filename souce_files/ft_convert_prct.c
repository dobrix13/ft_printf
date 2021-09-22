/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_prct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:55:58 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 00:05:53 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_convert_prct(t_holder *holder)
{
	holder->argument = ft_append_chr("", holder->conversion);
	if (!holder->left_justify)
		ft_fill_left_pad(&holder->argument, holder->padding, holder->width);
	else
		ft_fill_right_pad(&holder->argument, ' ', holder->width);
	holder->len = ft_strlen(holder->argument);
}
