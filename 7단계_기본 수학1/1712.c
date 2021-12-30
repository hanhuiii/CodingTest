#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	int a, b, c, num;
	scanf("%d %d %d", &a, &b, &c);
	if (b >= c)
		num = -1;
	else
		num = -a / (b - c) + 1;
	printf("%d", num);
	return 0;
}