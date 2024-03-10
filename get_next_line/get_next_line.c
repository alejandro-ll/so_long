/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:50:48 by marvin            #+#    #+#             */
/*   Updated: 2023/05/06 11:31:01 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_free_join(char *resto, char *buffer)
{
    char *tmp;
    
    if (!resto)
        resto = ft_calloc(1, 1);
    tmp = ft_strjoin(resto, buffer);
    free(resto);
    return (tmp);
}

char    *ft_read_file(int fd, char *resto)
{
    char    *buffer;
    int     c_read;

    if (!resto)
        resto = ft_calloc(1,1);
    buffer = ft_calloc(BUFFER_SIZE + 1, 1);
    if (!buffer)
        return (NULL);
    c_read = 1;
    while (!ft_strchr(resto,'\n') && c_read > 0)
    {
        c_read = read(fd, buffer, BUFFER_SIZE);
       /* if (c_read <= 0)  // no comtemplas que temp tenga algo y cortas la ejecucion del programa de manera prematura
        {
            printf("ESTE CABRON");
            free(resto);
            free(buffer);
            return (NULL);
        }*/
        buffer[c_read] = '\0';
        resto = ft_free_join(resto, buffer);
        if (buffer != NULL && ft_strchr(buffer, '\n'))
	        break ;
    }
    free (buffer);
    return (resto);
}

char    *ft_update_lines(char *buffer)
{
    int     i;
    int     j;
    char    *line;

    i = 0;
    j = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
    if (!line)
    {
        free(buffer);
        return (NULL);
    }
    i++;
    while (buffer[i] != '\0')
        line[j++] = buffer[i++];
    if (buffer[i] == '\n')
        line[j++] = buffer[i++];
    line[j] = '\0';
    free(buffer);
    return (line);
}

char    *ft_line(char *resto)
{
    int     i;
    char    *ln;

    i = 0;
    while (resto[i++] != '\0');
    if (i == 1)
        return (NULL);
    ln = ft_calloc(i, sizeof(char));
    if (!ln)
        return (NULL);
    i = 0;
    while (resto[i] && resto[i] != '\n')
    {
        ln[i] = resto[i];
        i++;
    }
    if (resto[i] && resto[i] == '\n')
	    ln[i++] = '\n';
    return (ln);
}

char    *get_next_line(int fd)
{
    static char    *resto;
    char           *ln;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	    return (NULL);
    //printf("=====================");
    //printf("SE EJECUTA LA FUNCION");
    //printf("=====================\n");
    resto = ft_read_file(fd, resto);
    if (!resto)
        return (NULL);
    ln = ft_line(resto);
    //printf("VALOR----> RESTO\n%s\n", resto);
    //printf("VALOR----> LINE\n%s\n", ln);
    resto = ft_update_lines(resto);
    //printf("VALOR----> RESTO\n%s\n", resto);
    return (ln);
}
/*
int main(void)
{
    int fd;
    char *line;

    fd = open("read_error.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file %s\n", "read_error.txt");
        return (1);
    }
    while ((line = get_next_line(fd)))
    {
        printf("EN CONSOLA--->%s\n", line);
        free(line);
    }
    printf("EN CONSOLA--->%s\n", line);
    close(fd);
    return (0);
}*/