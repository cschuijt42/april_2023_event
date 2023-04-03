#include <stdlib.h>
#include <stdio.h>

int max_width_for_layer(int layer_no) {
	int max_width = 0;

	int i = 0;
	while (i < layer_no) {
		i++;

		max_width += i + 2;

		if (i != layer_no) {
			max_width += 2 + ((i - 1) / 2);
		}
	}

	return (max_width);
}

int start_width_for_layer(int layer_no) {
	if (layer_no == 1)
		return (1);
	else
		return (max_width_for_layer(layer_no - 1) + 2 + (layer_no / 2));
}

void draw_pyramid_row(int width, int max_width) {
	int asterisks, padding;
	padding = max_width - width;
	while (padding) {
		printf(" ");
		padding--;
	}

	printf("/");

	asterisks = ((width - 1) * 2) + 1;
	while (asterisks) {
		printf("*");
		asterisks--;
	}
	
	printf("\\\n");
}

void draw_pyramid_row_door(int width, int max_width, int door_dims, int handle) {
	int asterisks, padding;
	padding = max_width - width;
	while (padding) {
		printf(" ");
		padding--;
	}

	printf("/");

	asterisks = ((width - 1) * 2) + 1 - door_dims;
	int i = 0;
	while (i < asterisks / 2) {
		printf("*");
		i++;
	}
	
	i = 0;
	while (i < door_dims)
	{
		if (handle && i + 2 == door_dims)
			printf("$");
		else
			printf("|");
		i++;
	}

	i = 0;
	while (i < asterisks / 2) {
		printf("*");
		i++;
	}

	printf("\\\n");
}

void draw_pyramid_layer(int layer_no, int max_width) {
	int current_width = start_width_for_layer(layer_no);
	int rows_to_draw  = layer_no + 2;

	int i = 0;
	while (i < rows_to_draw) {
		draw_pyramid_row(current_width, max_width);
		current_width++;
		i++;
	}
}

void draw_pyramid_layer_with_door(int layer_no, int max_width) {
	int current_width = start_width_for_layer(layer_no);
	int rows_to_draw  = layer_no + 2;
	int door_dimensions = layer_no % 2 ? layer_no : layer_no - 1;
	
	int i = 0;
	while (i < rows_to_draw)
	{
		if (i < rows_to_draw - door_dimensions)
			draw_pyramid_row(current_width, max_width);
		else if (door_dimensions > 3 && i == rows_to_draw - 1 - (door_dimensions / 2))
			draw_pyramid_row_door(current_width, max_width, door_dimensions, 1);
		else
			draw_pyramid_row_door(current_width, max_width, door_dimensions, 0);
		current_width++;
		i++;
	}
}

void draw_pyramids(int pyramid_size) {
	int max_width = max_width_for_layer(pyramid_size);

	int i = 1;
	while (i <= pyramid_size)
	{
		if (i == pyramid_size)
			draw_pyramid_layer_with_door(i, max_width);
		else
			draw_pyramid_layer(i, max_width);
		i++;
	}
}

int main(int ac, char **av) {
	if (ac != 2)
		return (0);
	
	int pyramid_size = atoi(av[1]);
	if (pyramid_size < 1)
		return (0);

	draw_pyramids(pyramid_size);

	return (0);
}
