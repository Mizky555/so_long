/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:06:40 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/19 02:15:36 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

void map_create(char **argv, t_game *s)//เปิดไฟล์อ่านเพื่อจับยัดลงstrที่จะใช้วิ่งจริง
{
    int fd;
    int h;

    h = 0;
    fd = open(argv[1],O_RDONLY);
    s->map_real = malloc(sizeof(char *) * s->height + 1);
    while (h < s->height)
    {
        s->map_real[h] = get_next_line(fd);
        h++; 
    }
    s->map_real[h] = NULL;
    close(fd);

    h = 0;
    fd = open(argv[1],O_RDONLY);
    s->map_play = malloc(sizeof(char *) * s->height + 1);
    while (h < s->height)
    {
        s->map_play[h] = get_next_line(fd);
        h++;
    }
    s->map_play[h] = NULL;
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
            print_error("Error map_xy -> lenght\n");
            free(s->map_check);
            free_map_play(s);
            free_map_real(s);
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
                    free_map_play(s);
                    free_map_real(s);
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
                    free_map_play(s);
                    free_map_real(s);
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
        free_map_play(s);
        free_map_real(s);
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


void    ff(t_game *s, char **map, int    h, int   l)
{
    if (ft_strchr("0CEP",map[h][l]) != NULL)//ft_strchr เช็คว่าถ้าไม่มีตัวใดตัวหนึ่งใน "" เลยจะ return NULL
        ff_count(s, map[h][l]);
    else if (map[h][l] == '1')
        return;
    map[h][l] = '1';//เปลี่ยนตัวที่เดินผ่านมาแล้วเป็นกำแพง
    ff(s, map, h - 1, l);// ^^Up^^
    ff(s, map, h + 1, l);// _Down_
    ff(s, map, h, l - 1);// <<left<<
    ff(s, map, h, l + 1);// >>right>>
    return;
}

void    ff_count(t_game *s,char map)//ฟ.นับว่ามีตัวที่ต้องเก็บและทางออกกี่ตัวเพื่อไปเช็คต่อใน ff_check
{
    if (map == 'C')
        s->player_eat_c++;
    else if (map == 'E')
        s->player_eat_e++;
    else
        return;
    return;
}

void    ff_check(t_game *s)//ฟ.เช็คว่าตัวที่เดินผ่านไปเก็บเหรียญครบไหมและ เดินไปทางออกได้ไหม
{
    if (s->player_eat_c != s->count_c || s->player_eat_e != 1)
    {
        printf("play_c = %d \n count_c = %d\n player_e = %d\n",s->player_eat_c,s->count_c,s->player_eat_e);
        print_error("Path error ff_check \n");
        free_map_play(s);
        free_map_real(s);
        exit(1);
    }
    free_map_real(s);
    return;
}

void    free_map_real(t_game *s)
{
    int i;

    i = 0;
    while (i < s->height)
    {
        free(s->map_real[i]);
        i++;
    }
    free(s->map_real);
    return;
}

void    free_map_play(t_game *s)
{
    int i;

    i = 0;
    while (i < s->height)
    {
        free(s->map_play[i]);
        i++;
    }
    free(s->map_play);
    return;
}

/*void    ff(t_game *s)//ย่อมาจากน้ำท่วม เช็คว่าเดินไปทางออกได้มั้ยและส่งเช็คว่าวิ่งเก็บเหรียญครบมั้ย ผิดดดดดด
{
    
    if (ft_strchr("0CE",s->map_real[s->player_h - 1][s->player_l]) != NULL)//^^^Up^^^
    {
        s->player_h--;
        ff_changandcheckeandcountc(s, s->map_real[s->player_h][s->player_l]);
        ff(s);
    }
    if (ft_strchr("0CE",s->map_real[s->player_h + 1][s->player_l]) != NULL)//down
    {
        s->player_h++;
        ff_changandcheckeandcountc(s, s->map_real[s->player_h][s->player_l]);
        ff(s);
    }
    if (ft_strchr("0CE",s->map_real[s->player_h][s->player_l - 1]) != NULL)//<<<left<<<
    {
        s->player_l--;
        ff_changandcheckeandcountc(s, s->map_real[s->player_h][s->player_l]);
        ff(s);
    }
    if (ft_strchr("0CE",s->map_real[s->player_h][s->player_l + 1]) != NULL)//>>>right>>>
    {
        s->player_l++;
        ff_changandcheckeandcountc(s, s->map_real[s->player_h][s->player_l]);
        ff(s);
    }
}*/


/*void    ff_changandcheckeandcountc(t_game *s, char   someting)
{
    printf("\n----------\n");
int i=0;
while (i < s->height)
{
    printf("%s",s->map_real[i]);
    i++;
}
printf("player[%d][%d]\n",s->player_h,s->player_l);
    if (someting == 'C')//เจอ c บวกเข้าไป
        s->player_eat_c++;

    else if(someting == 'E')
    {
        printf("%d %d\n",s->player_eat_c, s->count_c);
        if (s->player_eat_c == s->count_c)
        {
            printf("ERRORERRORERRORERRORERROR\n");//แมพถูกต้อง เก็บcครบและเดินถึง e ได้
            exit(1);
        }

    }
    s->map_real[s->player_h][s->player_l] = 'P';//เปลี่ยนตัวที่ผ่านมาแล้ว(ทำสัญลักษณ์)
    printf("player_eat_c = %d\n",s->player_eat_c);
}*/