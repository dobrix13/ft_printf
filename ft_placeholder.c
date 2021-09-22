/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:42:17 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 13:14:03 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




void	ft_placeholder(t_format *tmp)
{
	t_holder	*holder;

	tmp->i++;
	holder = ft_initialize_holder();
	ft_parse(tmp, holder);
	if (holder->conversion)
	{
		ft_type_conversion(tmp, holder);
		tmp->len += write(1, holder->argument, holder->len);
		free(holder->argument);
	}
	free(holder->prefix);
	free(holder);
}
