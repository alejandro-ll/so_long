/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:43:59 by allera-m          #+#    #+#             */
/*   Updated: 2023/03/27 13:02:57 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(len * sizeof(*s1));
	if (!dup)
		return (NULL);
	if (!s1)
		return (NULL);
	if (dup)
	{
		ft_memmove(dup, s1, len);
	}
	return (dup);
}
