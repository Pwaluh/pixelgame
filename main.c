#include "include/pixelated.h"

int	main()
{
	char	grid[2][9][16];
	char	grid_ia[2][9][16];
	char	*p_grid = &grid[0][0][0];
	char	*p_ia_grid = &grid_ia[0][0][0];
	int	user_input;
	int	turn;
	int	nbr_change;
	int nmc;

	turn = 1;
	nbr_change = 0;
	init_grid(p_grid, &grid_ia[0][0][0]);
	check_territory(grid[0][0][0], p_grid, &nbr_change);
	nbr_change = 0;

	nmc = ia_min(p_ia_grid);
	printf("\n");
	do
	{
		/* efface l'ecran: system("CLS"); (win)   /   printf("\33[H\33[2J"); (unix) */
		/*system("CLS");*/
		printf ("\33[H\33[2J");
		print_grid(p_grid);
		printf("------------------------------------------------------------------------------------------\n");
		printf("Nombre de tour: %d\tNombre de changement: %d\t\tNombre de tour minimum: %d\n", turn, nbr_change, nmc);
		printf("------------------------------------------------------------------------------------------\n");
		printf("1. (B)leu\t2. (R)ouge\t3. (V)ert\t4. (J)aune\t5. (O)range\t6. (M)auve\n");
		printf("0. Quitter\n");
		printf("\nQue voulez-vous faire? ");
		scanf("%d", &user_input);
		switch (user_input)
		{
			case 0:
                printf ("\33[H\33[2J");
                /* system("CLS"); */
				return (EXIT_SUCCESS);
			case 1:
				check_territory('B', p_grid, &nbr_change);
				change_color('B', p_grid, &turn);
				break;
			case 2:
				check_territory('R', p_grid, &nbr_change);
				change_color('R', p_grid, &turn);
				break;
			case 3:
				check_territory('V', p_grid, &nbr_change);
				change_color('V', p_grid, &turn);
				break;
			case 4:
				check_territory('J', p_grid, &nbr_change);
				change_color('J', p_grid, &turn);
				break;
			case 5:
				check_territory('O', p_grid, &nbr_change);
				change_color('O', p_grid, &turn);
				break;
			case 6:
				check_territory('M', p_grid, &nbr_change);
				change_color('M', p_grid, &turn);
				break;
			default:
				printf("Entrer un nombre entre 1 et 6\n");
				break;
		}
	} while (user_input != EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
