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
		return (max_width_for_layer(layer_no - 1));
}

void draw_pyramid_layer(int layer_no, int has_door, int max_width) {
	int current_width = 
}

void draw_pyramids(int pyramid_size) {
	int max_width = max_width_for_layer(pyramid_size);

	int i = 0;
	while (i < pyramid_size)
	{
		if (i + 1 == pyramid_size)
			draw_pyramid_layer(i, 1, max_width);
		else
			draw_pyramid_layer(i, 0, max_width);
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