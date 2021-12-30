#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	int n, i = 1;
	scanf("%d", &n);
	
	while (1) {
		n = n - i;
		if (n <= 0) {
			n = n + i;
			break;
		}
		i++;
	}
	if (i % 2 == 0)
		printf("%d/%d", n, i + 1 - n);
	else
		printf("%d/%d", i + 1 - n, n);
	return 0;
}