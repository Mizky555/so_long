#include "so_long.h"

void    check_file(char **argv)
{
    if (ft_strrchr(argv[1],'.') == NULL)
    {
        print_error("file error\n");
        exit(1);
    }
    if (ft_strncmp(ft_strrchr(argv[1],'.'),".ber",5))
    {
        print_error("file error\n");
        exit(1);
    }
}