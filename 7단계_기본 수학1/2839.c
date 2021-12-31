#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int five = n / 5;
	for (int i = 0; i < n / 5+1; i++) {
		if ((n - five * 5) % 3 != 0)
			five -= 1;
		else {
			printf("%d", five + (n - five * 5) / 3);
			break;
		}
		if (i == n/5)
			printf("-1");
	}
	
	return 0;
}