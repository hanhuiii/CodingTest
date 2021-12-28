#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N,X,num = 0;
	scanf("%d %d\n", &N, &X);

	if (N >= 1 && N <= 10000) {
		for (int i = 1; i <= N; i++) {
			scanf("%d ", &num);
			if (num < X) { printf("%d ", num); }
		}
	}
	return 0;
}