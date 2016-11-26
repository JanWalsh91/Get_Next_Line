/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:31:06 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/10 14:58:04 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Tests for any printable character. Returns 1 if true, 0 if false.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}
