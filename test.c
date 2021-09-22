/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 00:36:07 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 01:36:19 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/libft.h"

int main (void)
{
	char c = 'W';
	char *string = "wolfsburg";
	void *v_pnt;
	int num = 42;
	float num_f = 42.42;

	
	ft_printf("Hello world!\n");
	printf("Hello world!\n");
	ft_printf("%%: %%\n");
	printf("%%: %%\n");
	ft_printf("c: %c\n", c);
	printf("c: %c\n", c);
	ft_printf("s: %s\n", string);
	printf("s: %s\n", string);
	ft_printf("p: %p\n", v_pnt);
	printf("p: %p\n", v_pnt);
	ft_printf("i: %i\n", num);
	printf("i: %i\n", num);
	ft_printf("d: %d\n", num);
	printf("d: %d\n", num);
	ft_printf("\n");
	return 0;
}
