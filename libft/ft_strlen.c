/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:07:25 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 11:57:27 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	The strlen() function calculates the length of the string pointed to by s,
**	excluding the terminating null byte ('\0').
*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
