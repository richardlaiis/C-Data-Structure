#include <stdio.h>
#include <stdlib.h>
int main() {
	int *ptr;
	ptr = (int *)malloc(sizeof(int));
	int x;
	scanf("%d", &x);
	*ptr = x;
	printf("%d", *ptr);
	free(ptr);
}
