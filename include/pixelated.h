#ifndef __PIXELATED_H__
#define __PIXELATED_H__

 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>

#define MAX_COLOR 6

 void	init_grid(char *grid, char *grid_ia);
 void	print_grid(char *tab);
 int	rand_a_b(int a, int b);
 void	check_territory(char color, char *tab, int *nbr_change);
 int	change_color(char color, char *tab, int *turn);
 int	ia_min(char *grid);
 int	copy_grid(char *grid, char *grid_copy);
 int	count_territory(char *tab);
 int    ft_input_user(int *input);
#endif
