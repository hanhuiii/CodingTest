#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int n, res;
	int cycle = 0;
	scanf("%d", &n);
	res = n;
	if (n >= 0 && n <= 99) {
		while (1) {
			int num1 = res / 10;
			int num2 = res % 10;
			int sum = num1 + num2;
			int sum1 = sum % 10;
			res = num2*10+sum1;
			cycle++;
			if (n == res) { break; }
		}
	}
	printf("%d\n", cycle);
	return 0;
}