all : ex07/smallest ex08/blackjack ex09/frame ex14/sastantua 

ex07/smallest : ex07/smallest.c
	gcc ex07/smallest.c -o ex07/smallest

ex08/blackjack : ex08/blackjack.c
	gcc ex08/blackjack.c -o ex08/blackjack

ex09/frame : ex09/frame.c
	gcc ex09/frame.c -o ex09/frame

ex14/sastantua : ex14/sastantua.c
	gcc ex14/sastantua.c -o ex14/sastantua
