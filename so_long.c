/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:38:45 by tsirirak          #+#    #+#             */
/*   Updated: 2022/11/26 23:25:54 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 int    main(int argc,char **argv)
 {
   if (argc == 2)
   {
      int	fd;
	    char *str;

	    (void) argc;
	    str = NULL;
	    fd = open(argv[1], O_RDONLY);

	    str = get_next_line(fd);
	    printf("get_next_line = %s\n",str);
	    free(str);
	    str = NULL;
      
      printf("Hello Opal\n");
      
   }
   else
   {
    print_error("input argument error\n");
   }
   return(0);
 }

void    print_error(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        write(2,&str[i],1);
        i++;
    }
}

/*argc อากิวเม้นเค้า (int)
 argv อากิวเม้นเวยู้ (char(2D))
*/