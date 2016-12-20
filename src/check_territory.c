#include "../include/pixelated.h"

void	check_territory(char color, char *tab, int *nbr_change)
{
	int	i;
	int	j;
	char	*map;

	*nbr_change = 0;
	map = tab + 144;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 16)
		{
			if (i == 0 && j == 15)
			{
				/* Premiere ligne, derniere colonne */
				/* Je vérifie la cellule a gauche, en bas et en bas a gauche */
				if (*tab == color)
				{
					if (*(map - 1) == '1' || *(map + 15) == '1' || *(map + 16) == '1')
					{
						*map = '1';
						*nbr_change = *nbr_change + 1;
					}
				}
			}
			else if (i == 8 && j == 0)
			{
				/* Derniere ligne, premiere colonne */
				/* Je vérifie la cellule a droite, en haut et en haut a droite */
				if (*tab == color)
				{
					if (*(map - 16) == '1' || *(map - 15) == '1' || *(map + 1) == '1')
					{
						*map = '1';
						*nbr_change = *nbr_change + 1;
					}
				}
			}
			else if (i == 8 && j == 15)
			{
				/* Derniere ligne, derniere colonne */
				/* Je vérifie la cellule a gauche, en haut et en haut a gauche */
				if (*tab == color)
				{
					if (*(map - 1) == '1' || *(map - 16) == '1' || *(map - 17) == '1')
					{
						*map = '1';
						*nbr_change = *nbr_change + 1;
					}
				}
			}
			else if  (i == 0 && (j > 0 && j < 15))
			{
				/* Je me situe sur la premiere ligne */
				/* Je vérifie gauche, droite, bas gauche, bas droite */
				if (*tab == color)
				{
					if (*(map - 1) == '1' || *(map + 1) == '1' || *(map + 15) == '1'
							|| *(map + 16) == '1' || *(map + 17) == '1')
					{
						*map = '1';
						*nbr_change = *nbr_change + 1;
					}
				}
			}
			else if (i == 8 && (j > 0 && j < 15))
			{
				/* Je me situe sur la derniere ligne */
				/* Je vérifie, gauche, droite, haut, haut gauche, haut droite */
				if (*tab == color)
				{
					if (*(map + 1) == '1' || *(map - 1) == '1' || *(map - 15) == '1'
							|| *(map - 16) == '1' || *(map - 17) == '1')
					{
						*map = '1';
						*nbr_change = *nbr_change + 1;
					}
				}
			}
			else if (j == 0 && (i > 0 && i < 8))
			{
				/* Je me situe premiere colonne */
				/* Je vérifie, haut, bas, droite, haut droite, bas droite */
				if (*tab == color)
				{
					if (*(map - 16) == '1' || *(map - 15) == '1' || *(map + 1) == '1'
							|| *(map + 16) == '1' || *(map + 17) == '1')
					{
						*map = '1';
						*nbr_change = *nbr_change + 1;
					}
				}
			}
			else if (j == 15 && (i > 0 && i < 8))
			{
				/* Je me situe derniere colonne */
				/* Je vérifie, haut, bas, gauche, haut gauche, bas gauche */
				if (*tab == color)
				{
					if (*(map - 17) == '1' || *(map - 16) == '1' || *(map - 1) == '1'
							|| *(map + 15) == '1' || *(map + 16) == '1')
					{
						*map = '1';
						*nbr_change = *nbr_change + 1;
					}
				}
			}
			else
			{
				if (*tab == color)
				{
					if (*(map - 17) == '1' || *(map - 16) == '1' || *(map - 15) == '1'
							|| *(map - 1) == '1' || *(map + 1) == '1' || *(map + 15) == '1'
							|| *(map + 16) == '1' || *(map + 17) == '1')
					{
						*map = '1';
						*nbr_change = *nbr_change + 1;
					}
				}
			}
			j++;
			tab++;
			map++;
		}
		i++;
	}
}
