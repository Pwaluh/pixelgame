#include "../include/pixelated.h"

int	ia_min(char *grid)
{
	/* L'ia doit determiner le nombre de coup minimum dans le quel le jeu peux etre terminer. */
	/* Une copie de grid a chaque instant T, effectuer tout les tests de couleur, sauvegarde  */
	/* du nombre de  changement */

	char	grid_copy[2][9][16];
	char	color_grid[MAX_COLOR] = {'B', 'R', 'V', 'J', 'O', 'M'};
	int	nbr_change[6] = {-1, -1, -1, -1, -1, -1};
	short	l;
	short	i;
	short   j;
	int	dump;
	int	nbr_territory = 0;
	int	color;
	int previous_color = 0;
	int nbr_tour = 0;

	/* Boucle tant que le nombre de territoire controlé est inférieur a la surface de jeu (144)*/
	while (nbr_territory < 144)
	{
	    j = 0;
	    /* Reset du tableau de changement */
	    while (j < 6)
	    {
            nbr_change[j] = -1;
            j++;
	    }
		color = 0;
		l = 0;
		i = 0;
		/* Test du nombre de changement pour chaque couleur dans une copie de tableau au tour */
		/* de jeu T */
		while (l < 6)
		{
			copy_grid(grid, &grid_copy[0][0][0]); /* re creer une copie a l'instant T de la grille */
			if (previous_color != l)
                check_territory(color_grid[l], &grid_copy[0][0][0], &nbr_change[l]);
			l++;
		}
		/* Quel couleur à effectuer le plus de changement? */
		while (i < 6)
		{
			if (nbr_change[i] > nbr_change[color])
			{
				color = i;
				i++;
			}
			else
				i++;
		}
		/* Aggrandissement du territoire et vérification du nombre de territoire */
		check_territory(color_grid[color], grid, &dump);
		change_color(color_grid[color], grid, &nbr_tour);
		previous_color = color;
		nbr_territory = count_territory(grid);
	}
	return (nbr_tour);
}
