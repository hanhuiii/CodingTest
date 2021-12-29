#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	int num1, num2;
	int n[3];
	
	scanf("%d", &num1);
	n[0] = num1 % 10;
	n[1] = (num1 / 10) % 10;
	n[2] = (num1 / 100) % 10;
	num1 = 100 * n[0] + 10 * n[1] + n[2];
	
	scanf("%d", &num2);
	n[0] = num2 % 10;
	n[1] = (num2 / 10) % 10;
	n[2] = (num2 / 100) % 10;
	num2 = 100 * n[0] + 10 * n[1] + n[2];

	if (num1 > num2)
		printf("%d", num1);
	else
		printf("%d", num2);

	return 0;
}