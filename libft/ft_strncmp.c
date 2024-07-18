/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:52:20 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:38:21 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	i = 0;
	while ((s1a[i] != '\0' || s2a[i] != '\0') && i < n)
	{
		if (s1a[i] == '\0')
		{
			return (-s2a[i]);
		}
		else if (s2a[i] == '\0')
		{
			return (s1a[i]);
		}
		if (s1a[i] == s2a[i])
			i++;
		else
		{
			return (s1a[i] - s2a[i]);
		}
	}
	return (0);
}
