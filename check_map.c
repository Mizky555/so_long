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

void map_create(char **argv, t_game *s)//เปิดไฟล์อ่านเพื่อจับยัดลงstrที่จะใช้วิ่งจริง
{
    int fd;
    int h;

    h = 0;
    fd = open(argv[1],O_RDONLY);
    s->map_real = malloc(sizeof(char *) * s->height + 1);
    while (h <= s->height - 1)
    {
        s->map_real[h] = get_next_line(fd);
        h++; 
    }
    s->map_real[h] = NULL;
    close(fd);
}

int map_check_rectangle(char **argv, t_game *s)//เช็คว่าเป็น 4 เหลี่ยมไหม
{
    int fd;
    
    s->height = 0;
    fd = open(argv[1],O_RDONLY);
    s->map_check = get_next_line(fd);//เก็บเพื่อใช้นับ height lenght(ทำลีละบรรทัดแล้วฟรี)
    s->lenght = sl_strlen(s->map_check);//นับlenghtของบรรทัดแรก->ใช้เทียบกับบรรทัดที่เหลือ
    while (s->map_check)
    {
        free(s->map_check);
        s->map_check = get_next_line(fd);
        if (s->map_check && sl_strlen(s->map_check) != s->lenght)
        {//เข้าเมื่อความยาวของบรรทัดต่อมาไม่เท่ากับความยาวของบรรทัดแรก
            free(s->map_check);
            print_error("Error map_xy -> lenght\n");
            exit(1);
        }
        s->height++;
    }
    free(s->map_check);
    close(fd);
    return(0);
}



void map_wallandpart(t_game *s)//วนเช็คกำแพวรอบกรอบและตัวต่างๆและส่งนับว่าเกินมั้ย
{
    int h;
    int l;
    
    h = 0;
    while (h < s->height)
    {
        l = 0;
        if (h == 0 || h == s->height - 1)//เช็ตกำแพงแถวบนล่าง
        {
            while (l < s->lenght)
            {
                if (s->map_real[h][l] != '1')
                {
                    print_error("Error map_wall if");
                    h = 0;
                    while (h <= s->height - 1)
                    {
                        free(s->map_real[h]);
                        h++; 
                    }
                    free(s->map_real);
                    exit(1);
                }
                l++; 
            }
        }
        else//เช็คกรอบแถวกลางที่ไม่ใช่บนล่าง
        {
            while (l < s->lenght)
            {
                /*
                if (ft_strchr("01CPE", s->map[h][l] )== NULL)
                {
                    print_error("Error part map_wallandpart");
                    exit(1);
                }*/
                map_count_part(s->map_real[h][l], s);//ส่งไปนับจำนวนส่วนประกอบ
                if (s->map_real[h][l] == 'P')
                {
                    s->player_h = h;
                    s->player_l = l;
                }
                if (s->map_real[h][0] != '1' || s->map_real[h][s->lenght - 1] != '1')
                {
                    print_error("Error map_wall else");
                    h = 0;
                    while (h <= s->height - 1)
                    {
                        free(s->map_real[h]);
                        h++; 
                    }
                    free(s->map_real);
                    exit(1);
                }
                l++;
                
            }
        }
        h++;
    }
    map_count_part_check(s);//ส่งไปเช็คตัวประกอบ
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

void    map_count_part(char part, t_game *s)//เช็คว่ามีตัวต่างๆจำนวนเท่าไหร่
{
    if (part == '0' || part == '1')
        return ;
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
}

void    map_count_part_check(t_game *s)//เช็คว่าตัวต่างๆที่มีอยู่ในกฎที่กำหนดมั้ย
{
    if (s->count_c < 1 || s->count_e > 1 || s->count_p > 1){
        print_error("Error map count part check");
        exit(1);
    }
        printf("s->count_c = %d\n",s->count_c);
        printf("s->count_e = %d\n",s->count_e);
        printf("s->count_p = %d\n",s->count_p);
}
/*
void    ff(t_game *s)//ย่อมาจากน้ำท่วม เช็คว่าเดินไปทางออกได้มั้ยและส่งเช็คว่าวิ่งเก็บเหรียญครบมั้ย
{
    if (s->str_real[h-1][l] == 'C' || s->str_real[h-1][l] == '0' )
    {
        s->str_real[h][l]=0;
        h++;
        s->str_real[h][l]=0;//ไม่แน่ใจว่าต้องอยู่บนอยู่ล่าง
    }

}*/