#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int m, num;
	int max = -1000001;

	
	for (int i = 0; i < 9; i++) {
		scanf("%d", &num);
		if (num >= 1 && num < 100) {
			if (num > max) {
				max = num;
				m = i + 1;
			}
		}
	}
	printf("%d\n%d", max, m);
	return 0;
}