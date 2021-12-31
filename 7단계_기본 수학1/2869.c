#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);

	if (a >= v)
		printf("1");
	else 
		printf("%d", (v - a-1) / (a - b) + 2);
	
	return 0;
}