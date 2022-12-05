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

int map_xy(char **argv, t_game *s)//เช็คว่าเป็น 4 เหลี่ยมไหม
{
    int fd;
    
    s->height = 0;
    fd = open(argv[1],O_RDONLY);
    s->str_map = get_next_line(fd);//เก็บเพื่อใช้นับ height lenght(ทำลีละบรรทัดแล้วฟรี)
    s->lenght = sl_strlen(s->str_map);//นับlenghtของบรรทัดแรก->ใช้เทียบกับบรรทัดที่เหลือ
    printf("lenght = %d\n",s->lenght);
    map_checkwall(s->str_map,s->height,s->lenght,1);
    while (s->str_map)
    {
        free(s->str_map);
        s->str_map = get_next_line(fd);
        map_checkwall(s->str_map,s->height,sl_strlen(s->lenght),2);
        printf("s->str_map = %s\n",s->str_map);
        if (s->str_map && sl_strlen(s->str_map) != s->lenght)
        {//เข้าเมื่อความยาวของบรรทัดต่อมาไม่เท่ากับความยาวของบรรทัดแรก
            free(s->str_map);
            print_error("Error map_xy -> lenght\n");
            exit(1);
        }
        s->height++;
    }
    map_checkwall(s->str_map,s->height,s->lenght,1);//เช็คบรรทัดสุดท้าย (hight - 1)
    printf("hight = %d\n", s->height);
    free(s->str_map);
    return(0);
}

void    map_checkwall(char **str, int    height, int  lenght, int mode)
{
    int l;

    l = 0;
    while (lenght > l)
    {
        if (height == 0 && str[height][l] != 1 || mode = 1)
        {
            printf("Error check wall");
            exit(1);
        }
        else if (str[height][0] && str[height][lenght - 1] != 0)
        {
            printf("Error check wall");
            exit(1);
        }
        l++;
    }
}

void map_wall(t_game *s)
{
    int h;
    
    h = 0;
    while (h <= s->height)
    {
        int l;
        
        l = 0;
        if (h == 0 || h == s->height - 1)
        {
            while (l < s->lenght)
            {
                if (s->str_map[h][l] != '1')
                {
                    print_error("Error map_wall");
                    exit(1);
                }
            l++; 
            }
        }
        else
        {
            while (l < s->lenght)
            {
                if (s->str_map[h][0] != 0 || s->str_map[h][s->lenght - 1] != 0)
                {
                    print_error("Error map_wall");
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
