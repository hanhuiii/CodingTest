#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int num, remainder,same=0;
	int arr[42] = { 0, };
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num);
		remainder = num % 42;
		arr[remainder]++;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i] == 0) { same++; }
	}
	printf("%d", 42 - same);
	return 0;
}