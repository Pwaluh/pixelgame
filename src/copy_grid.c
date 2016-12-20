#include "../include/pixelated.h"

int	copy_grid(char *grid, char *grid_copy)
{
	/*copy une grille, voir plus tard pour la mettre en void* avec tableau pour les tailes*/
	short	i;
	char	*grid_beginning;

	grid_beginning = grid;
	i = 0;

	while (i < 288)
	{
		i++;
		*grid_copy = *grid;
		grid++;
		grid_copy++;
	}

	grid = grid_beginning;
	return (0);
}
