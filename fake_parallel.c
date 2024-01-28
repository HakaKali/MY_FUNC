#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clrscr() {
	printf("\e[1;1H\e[2J");
}

void printxy(int x, int y, char *str) {
	printf("\033[%d;%dH%s\n", y, x, str);
}

typedef struct pos {
	int x;
	int y;
} pos_t;

void print_and_advance(pos_t *p, char *str, long miliseconds) {
	if (p->x > 0)
		printxy(p->x-1, p->y, " ");
	printxy(p->x, p->y, str);
	if(++p->x > 60)
		p->x = 0;
	
	printxy(0,0, " ");
	usleep(miliseconds);
}

int main (int argc, char **argv) {
	long miliseconds = 6000;
	if (argc > 1)
		miliseconds = atoi(argv[1]); 

	clrscr();

	pos_t p1 = {0, 5};
	pos_t p2 = {0, 10};

	pos_t p[5] = { {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9} };

	while (1) {
		for (int i = 0; i < 5; i++) 
			print_and_advance(&p[i], "|", miliseconds);
	}


	return 0;
}
