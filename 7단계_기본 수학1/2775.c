#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int person(int a, int b) {
	if (a == 0)
		return b;
	if (b == 1)
		return 1;
	return person(a - 1, b) + person(a, b - 1);
}
int main() {
	int t, k, n;
	int num[15];
	
	scanf("%d", &t);
	for (int a = 0; a < t; a++) {
		scanf("%d", &k);
		scanf("%d", &n);
		
		printf("%d\n", person(k, n));
	}
	
	return 0;
}