#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	int n, m, i = 1;
	scanf("%d", &n);
	if ( n - 1 != 0 ) {
		n = n - 1;
		while (1) {
			n -=  6 * i;
			i++;
			if (n <= 0)
				break;
		}
	}
	printf("%d", i);
	return 0;
}