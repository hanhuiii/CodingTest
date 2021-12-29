#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

int d(int n) {
	int sum = n;
	while (n > 0) {
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

int main() {
	int number[10001] = { 0, };
	for (int i = 1; i <= 10000; i++) {
		int res = d(i);
		if(res<=10000)
			number[res]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (number[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}