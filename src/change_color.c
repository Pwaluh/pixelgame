#include "../include/pixelated.h"

int	change_color(char color, char *tab, int *turn)
{
	int	i;
	int	j;
	char	*map;

	map = tab + 144;
	i = 0;
	j = 0;
	/* Parcours de la "2eme" dimension et changement de couleur pour les nouveau territoires*/
	while (i < 144)
	{
		if (*map == '1')
		{
			j++;
			tab = map - 144;
			*tab = color;
		}
		map++;
		i++;
	}
	if (j != 144)
		*turn += 1;
	return (j);
}
