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
   
   if (argc == 2) //ต้องรับค่าเข้ามาแค่สอง ได้แก่ ./a.out Map/Map1.ber ถ้าไม่ใช่เข้า else
   {
      map_xy(argv, &s);
      map_wall(t_game *s);
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