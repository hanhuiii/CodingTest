#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int han(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (0 < i && i < 100) count++;
		else if (i < 1000) {
			if (i % 10 - (i / 10) % 10 == (i / 10) % 10 - (i / 100) % 10) count++;
		}
	}
	return count;
}
int main(void) {
	int x, res;
	scanf("%d", &x);
	res = han(x);
	printf("%d", res);

	return 0;
}