/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:38:45 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/05 16:52:26 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 int    main(int argc,char **argv)
 {
   t_game   s;

   s.count_c = 0;
   s.count_e = 0;
   s.count_p = 0;
   s.player_eat_c = 0;
   if (argc == 2) //ต้องรับค่าเข้ามาแค่สอง ได้แก่ ./a.out Map/Map1.ber ถ้าไม่ใช่เข้า else
   {
      map_check_rectangle(argv, &s);
      map_create(argv, &s);
      map_wallandpart(&s);
      ff(&s, s.map_real, s.player_h, s.player_l);
      ff_check(&s);
      int   i = 0;
      while (i < s.height)
      {
         printf("%s",s.map_play[i++]);
      }

      return(0);
   }
   else
   {
      print_error("input argument error\n");
   }
   return(0);
 }


void    print_error(char *str)
{
   write(2,"Error\n",6);
   write(2,str, ft_strlen(str));

}

/*argc อากิวเม้นเค้า (int)
 argv อากิวเม้นเวยู้ (char(2D))
*/