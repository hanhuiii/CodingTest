#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int n, num;
	int max = -1000001;
	int min = 1000001;

	scanf("%d", &n);
	if (n >= 1 && n <= 1000000) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &num);
			if (num > max) {
				max = num;
			}
			if (num < min) {
				min = num;
			}
		}
	}
	printf("%d %d", min, max);
	return 0;
}