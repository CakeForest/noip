#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int n ;
int R() {
	return rand() * rand() % (n * 10);
}

int main() {
	srand(time(0));
	for (int t = 1; t <= 10; t++) {
		if (t <= 4) n = 100;
		else if (t <= 9) n = 100000;
		else n = 4000000;
		char input[50];
		sprintf(input, "editor%d.in", t);
		//ofstream fout(input);
		freopen(input, "w", stdout);
		for (int i = 1; i <= n; i++) printf("%c", 'A' + rand() % 26);
		printf("\n%d\n", n);
		for (int i = 1; i <= n; i++) {
			int opt = rand() % 5;
			char dir = (rand() % 2) ? 'L' : 'R';
			if (i == n) printf("S\n");
			else if (opt == 0) printf("< %c\n", dir);
			else if (opt == 1) printf("> %c\n", dir);
			else if (opt == 2) printf("I %c %c\n", dir, 'A' + rand() % 26);
			else if (opt == 3) printf("D %c\n", dir);
			else printf("R\n");
		}
	}
	return 0;
}