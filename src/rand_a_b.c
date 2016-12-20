#include "../include/pixelated.h"

/* Fonction de nombre aléatoire [a;b[ */
int	rand_a_b(int a, int b)
{
	return rand() % (b - a) + a;
}
