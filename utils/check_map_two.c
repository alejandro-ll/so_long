/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:03:45 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/11 01:54:30 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2) {
    // Iterar sobre ambos strings mientras los caracteres sean iguales y no lleguemos al final
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    // Devolver la diferencia entre los caracteres donde difieren o cero si son iguales
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int	check_ber(char *filename)
{
	size_t len = ft_strlen(filename);

    if (len < 4) {
        return 0;
    }
    return (ft_strcmp(filename + len - 4, ".ber") == 0);
}
