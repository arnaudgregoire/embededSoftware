#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void arithmetique(int* div, int* mult, int* diff, int* sum, int a, int b){
	*div = a/b;
	*mult = a*b;
	*diff = a-b;
	*sum = a+b;
}

int main(int argc, char const *argv[]) {
	int div, mult, diff, sum;
	arithmetique(&div, &mult, &diff, &sum, 10, 5);

	printf("%i\n", div);
	return 0;
}