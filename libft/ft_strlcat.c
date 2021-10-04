/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:37:21 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/29 13:00:21 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	The strlcpy() and strlcat() functions copy and concatenate strings re‐
**	spectively.  They are designed to be safer, more consistent, and less er‐
**	ror prone replacements for strncpy(3) and strncat(3).  Unlike those func‐
**	tions, strlcpy() and strlcat() take the full size of the buffer (not just
**	the length) and guarantee to NUL-terminate the result (as long as size is
**	larger than 0 or, in the case of strlcat(), as long as there is at least
**	one byte free in dst).  Note that a byte for the NUL should be included
**	in size.  Also note that strlcpy() and strlcat() only operate on true “C”
**	strings.  This means that for strlcpy() src must be NUL-terminated and
**	for strlcat() both src and dst must be NUL-terminated.
*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (size + srclen);
	if (size <= dstlen)
		srclen += size;
	else
		srclen += dstlen;
	i = 0;
	while (src[i] && dstlen + 1 < size)
		dst[dstlen++] = src[i++];
	dst[dstlen] = '\0';
	return (srclen);
}
