/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:06:40 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/05 19:58:10 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/fcntl.h>

int map_check_rectangle(char **argv, t_game *s)//เช็คว่าเป็น 4 เหลี่ยมไหม
{
    int fd;
    
    s->height = 0;
    fd = open(argv[1],O_RDONLY);
    s->str_map = get_next_line(fd);//เก็บเพื่อใช้นับ height lenght(ทำลีละบรรทัดแล้วฟรี)
    s->lenght = sl_strlen(s->str_map);//นับlenghtของบรรทัดแรก->ใช้เทียบกับบรรทัดที่เหลือ
    while (s->str_map)
    {
        free(s->str_map);
        s->str_map = get_next_line(fd);
        if (s->str_map && sl_strlen(s->str_map) != s->lenght)
        {//เข้าเมื่อความยาวของบรรทัดต่อมาไม่เท่ากับความยาวของบรรทัดแรก
            free(s->str_map);
            print_error("Error map_xy -> lenght\n");
            exit(1);
        }
        s->height++;
    }
    free(s->str_map);
    close(fd);
    return(0);
}

void map_create(char **argv, t_game *s)
{
    int fd;
    int h;

    h = 0;
    fd = open(argv[1],O_RDONLY);
    s->map = malloc(sizeof(char *) * s->height + 1);
    while (h <= s->height - 1)
    {
        s->map[h] = get_next_line(fd);
        h++; 
    }
    s->map[h] = NULL;
    close(fd);
}

void map_wallandpart(t_game *s)
{
    int h;
    int l;
    
    h = 0;
    while (h < s->height)
    {
        l = 0;
        if (h == 0 || h == s->height - 1)
        {
            while (l < s->lenght)
            {
                if (s->map[h][l] != '1')
                {
                    print_error("Error map_wall if");
                    h = 0;
                    while (h <= s->height - 1)
                    {
                        free(s->map[h]);
                        h++; 
                    }
                    free(s->map);
                    exit(1);
                }
                l++; 
            }
        }
        else
        {
            while (l < s->lenght)
            {
                if (ft_strchr("01CPE", s->map[h][l] )== NULL)
                {
                    print_error("Error part map_wallandpart");
                    exit(1);
                }
                if (s->map[h][0] != '1' || s->map[h][s->lenght - 1] != '1')
                {
                    print_error("Error map_wall else");
                    h = 0;
                    while (h <= s->height - 1)
                    {
                        free(s->map[h]);
                        h++; 
                    }
                    free(s->map);
                    exit(1);
                }
                l++;
            }
        }
        h++;
        
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
/*
void    map_count_part(char part, t_game *s)
{
    s->count_c = 0;
    s->count_e = 0;
    s->count_p = 0;
    if (part == '0' || part == '1');
    else if (part == 'C')
        s->count_c++;
    else if (part == 'E')
        s->count_e++;
    else if (part == 'P')
        s->count_p++;
    else
    {
        print_error("Error map character");
        exit(1);    
    }
}*/