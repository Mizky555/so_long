/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:06:40 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/05 02:46:46 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_xy(char **argv, t_game *s)
{
    int fd;
    
    s->height = 0;
    fd = open(argv[1],O_RDONLY);
    s->str_map = get_next_line(fd);
    s->lenght = sl_strlen(s->str_map);
    printf("lenght = %d\n",s->lenght);
    while (s->str_map)
    {
        free(s->str_map);
        s->str_map = get_next_line(fd);
        printf("s->str_map = %s\n",s->str_map);
        if (s->str_map && sl_strlen(s->str_map) != s->lenght){
            free(s->str_map);
            print_error("Error map_xy -> lenght\n");
            exit(1);
        }
        s->height++;
    }
        printf("Hello\n");
    printf("hight = %d\n", s->height);
    free(s->str_map);
    return(0);
}

int map_wall(char   **str, t_game *s)
{
    int h;
    
    h = 0;
    while (h <= s->height)
    {
        int l;
        
        l = 0;
        while (l < s->lenght)
        {
            if (str[h][l] != '1')
            {
                print_error("Error map_wall");
                exit(1);
            }
            l++; 
        }
        h = h-;
    }
    
}

int	sl_strlen(char *s)
{
	int	i;
    int len;

	i = 0;
    len = 0;
	while (s[i] != '\0')
    {
        if (s[i] != '\n')
            len++;
        i++;
    }
    return (len);
}
