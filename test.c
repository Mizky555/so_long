#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char **map;

    map = calloc(sizeof(char **), 4);

    for (int i=0;i < 3; )
    {
        map[i] = strdup("hello");
    }
    printf("%p\n", map);
    for (int i=0;i < 3; i++)
    {
        printf("%p %s\n", map[i], map[i]);
    }

    return (0);
}