#include "../include/pixelated.h"

int	count_territory(char *tab)
{
	int	i;
	int	j;
	char	*map;

	map = tab + 144;
	i = 0;
	j = 0;
	/* Parcours la deuxieme dimension et compte le nbr de territoire controlé */
	while (i < 144)
	{
		if (*map == '1')
		{
			j++;
		}
		map++;
		i++;
	}
	return (j);
}
