#include <stdio.h>
int main () {
	int i = 0;
	int j = 0;
	
	for(i = 0; i < 10; i++) {
		for(j = 1; j <= i; j++) {
			printf("%dx%d=%2d ", i, j, i * j);
		}
		printf("\n");
	}

    return 0;
}
