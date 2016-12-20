#include "../include/pixelated.h"

void	print_grid(char *tab)
{
	int	k;
	int	i;
	int	j;
	int	debbug;

	k = 0;
	i = 0;
	j = 0;
	debbug = 0;

	/* Parcours le tableau et affiche le contenu. Debbug sert à afficher ou non la carte */
	/* des territoires conquis */
	while (k < 2)
	{
		if (k == 0)
		{
			while (i < 9)
			{
				while (j < 16)
				{
					if (j == 15)
						printf("%c  \n\n", *tab);
					else
						printf("%c   ", *tab);
					j++;
					tab++;
				}
				i++;
				j = 0;
			}
		}
		else
		{
			if (debbug == 0)
			{
				i = 0;
				printf("\n\n");
				while (i < 9)
				{
					while (j < 16)
					{
						if (j == 15)
							printf("%c\n", *tab);
						else
							printf("%c ", *tab);
						j++;
						tab++;
					}
					i++;
					j = 0;
				}
			}
		}
		k++;
	}
}
