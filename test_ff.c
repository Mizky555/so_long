#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	flooding(char **map, int x, int y, int height, int length)
{
	int	j;
	// printf("%d %d %d %d\n",x,y,height,length);
	if (y < 0 || x < 0 || y > height - 1|| x > length - 1)
		return ;
	if (map[y][x] == '1' || map[y][x] == ' ' || map[y][x] == '\0')
		return ;



	j = 0;
	while (j < height)
		printf("%s", map[j++]);
	printf("\n");
	map[y][x] = ' ';




	flooding(map, x + 1, y, height, length);
	flooding(map, x, y + 1, height, length);
	flooding(map, x - 1, y, height, length);
	flooding(map, x, y - 1, height, length);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

void    ff(char	**map, int h, int l, int height, int lenght)//ย่อมาจากน้ำท่วม เช็คว่าเดินไปทางออกได้มั้ยและส่งเช็คว่าวิ่งเก็บเหรียญครบมั้ย
{
	int j = 0;
	while (j < height)
		printf("%s",map[j++]);
	printf("\n====\n");
    if (ft_strchr("0CE",map[h - 1][l]) != NULL)//^^^Up^^^
    {
		printf("move up\n");
        h--;
		map[h][l] = ' ';
        ff(map,h,l, height, lenght);
    }
    if (ft_strchr("0CE",map[h + 1][l]) != NULL)//down
    {
		printf("move down\n");
        h++;
		map[h][l] = ' ';
        ff(map,h,l, height, lenght);
    }
    if (ft_strchr("0CE",map[h][l - 1]) != NULL)//<<<left<<<
    {
		printf("move left\n");
        l--;
		map[h][l] = ' ';
        ff(map,h,l, height, lenght);
    }
    if (ft_strchr("0CE",map[h][l + 1]) != NULL)//>>>right>>>
    {
		printf("move right\n");
        l++;
		map[h][l] = ' ';
        ff(map,h,l, height, lenght);
    }
	

}


void	floodfill(char **map,int height, int length)
{
	int	x = 0;
	int	y = 0;
	// printf("\n");
	while (map[y] && map[y][x] != 'P')
	{
		x = 0;
		while(map[y][x] && map[y][x] != 'P')
		{
			// printf("%c",map[y][x]);
			if (map[y][x] == 'P')
			{
				break;
			}
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	// printf("%d %d\n", y,x );
	// flooding(map, x, y,height, length);
	// printf("\e[41m==========\e[0m\n");
	ff(map, y, x,height, length);
}

int	main(int argc, char **argv)
{
	FILE	*fd;
	char	*line = NULL;
	size_t	len = 0;
	int		height = 0;
	char	**map;
	int		i = 0;
	int		j = 0;

	fd = fopen(argv[1], "r");
	while (getline(&line, &len, fd) != -1)
	{
		// free(line);
		// printf("%s",line);
		height++;
	}
	// printf("\n");
	fclose(fd);
	map = (char **)calloc(sizeof(char *), height + 1);
	fd = fopen(argv[1], "r");
	while (getline(&line, &len, fd) != -1)
	{
		map[i++] = strdup(line);
	}
	fclose(fd);
	// while (j < i)
		// printf("%s",map[j++]);
	floodfill(map, height, (int)len);
	j = 0;
	while (j < i)
		printf("%s",map[j++]);
	while (j < i)
		free(map[j++]);
	free(line);
	free(map);
	return (0);
}
