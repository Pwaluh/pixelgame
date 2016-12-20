#include "../include/pixelated.h"

void	init_grid(char *grid, char *grid_ia)
{
	char	color_grid[MAX_COLOR] = {'B', 'R', 'V', 'J', 'O', 'M'};
	int	random_number;
	int	k; 	/*compteur "hauteur"*/
	int	i; 	/*compteur "colonne"*/
	int	j; 	/*compteur "ligne"*/

	k = 0;
	i = 0;
	j = 0;
	srand(time(NULL));

    /* Initialisation de la grille de jeu + grille de jeu pour IA */
    /* Tableau à trois dimension [Z][Y][X] */
    /* Z = 0 ==> surface des couleurs */
    /* Z = 1 ==> surface de controle de territoire */
	while (k < 2)
	{
		if (k == 0)
		{
			while (i < 9)
			{
				while (j < 16)
				{
					random_number = rand_a_b(0, MAX_COLOR);
					*grid = color_grid[random_number];
					*grid_ia = color_grid[random_number];
					j++;
					grid++;
					grid_ia++;
				}
				j = 0;
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < 9)
			{
				while (j < 16)
				{
					if (i == 0 && j == 0)
					{
						*grid = '1';
						*grid_ia = '1';
					}
					else
					{
						*grid = '0';
						*grid_ia = '0';
					}
					j++;
					grid++;
					grid_ia++;
				}
				j = 0;
				i++;
			}
		}
		k++;
	}
}
