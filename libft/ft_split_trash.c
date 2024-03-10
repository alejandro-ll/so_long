/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:27:48 by allera-m          #+#    #+#             */
/*   Updated: 2023/04/04 17:24:06 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill_arr(char **arr, char const *s2, int y, int max_index)
{
	int	x;

	x = 0;
	while (x < max_index)
	{
		arr[y][x] = *s2;
		s2++;
		x++;
	}
	arr[y][x] = '\0';
}

int	ft_count_words(const char *s, int c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (words);
}

void    ft_count_ch(char **arr, char const *s, int c)
{
    int        i;
    int        y;
    int        chars;
    char    *s2;
    int        start;

    i = 0;
    y = 0;
    chars = 0;
    start = 0;
    s2 = (char *)s;
    while (s[i] != '\0')
    {
        chars = 0;
        while (s[i] != c && s[i] != '\0')
        {
            chars++;
            i++;
        }
        if (chars > 0)
        {
            arr[y] = (char *)malloc(sizeof(char) * (chars + 1));
            ft_fill_arr(arr, &s2[i - chars], y, chars);
            y++;
        }
        if (s[i] != '\0')
            i++;
        start = i;
    }
    arr[y] = NULL;
}



char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		words;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	ft_count_ch(arr, s, c);
	i = 0;
	if (!arr[i])
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		return (NULL);
	}
	return (arr);
}

/*
int main(void)
{
	char const s[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char c = ' ';
	
	ft_split(s, c);
}*/

/*void	ft_count_ch(char **arr, char const *s, int c)
{
	int		i;
	int		y;
	int		chars;
	char	*s2;
	int		start;

	i = 0;
	y = 0;
	chars = 0;
	start = 0;
	s2 = (char *)s;
	while (s[i] != '\0')
	{
		chars = 0;
		while (s[i] != c && s[i] != '\0')
		{
			chars++;
			i++;
		}
		if (s[i] != '\0')
			i++;
		arr[y] = (char *)malloc(sizeof(char) * (chars + 1));
		ft_fill_arr(arr, &s2[start], y, chars);
		start = start + i;
		y++;
	}
	arr[y] = NULL;
}*/