#include <stdio.h>
#include <stdlib.h>

void add_card_value(int *hand_value, char c) {
	static int full_aces = 0;
	int value            = 0;

	if (c >= '2' && c <= '9')
		*hand_value += (c - 48);
	else if (c == 'T' || c == 'J' || c == 'D' || c == 'K')
		*hand_value += 10;
	else if (c == 'A')
	{
		*hand_value += 11;
		full_aces++;
	}
	else
	{
		dprintf(2, "Invalid input!\n");
		exit(1);
	}

	while (full_aces && *hand_value > 21)
	{
		full_aces--;
		*hand_value -= 10;
	}
}

int	main(int ac, char **av) {
	char	*pnt;

	if (ac != 2)
		exit(1);

	int	hand_value = 0;
	// int	num_cards  = 0;
	pnt = av[1];

	while (*pnt) {
		add_card_value(&hand_value, *pnt);
		// num_cards++;
		pnt++;
	}

	if (/* num_cards == 2 && */hand_value == 21)
		printf("Blackjack!\n");
	else
		printf("%d\n", hand_value);

	return(0);
}
