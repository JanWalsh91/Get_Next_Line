/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:29:32 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/10 15:29:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assigns \0 to all chars of the string s.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		bzero(s, ft_strlen(s));
}