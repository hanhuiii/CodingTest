#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int n, sum=0;
	char input[100];
	scanf("%d", &n);
	scanf("%s", input);
	
	for (int i = 0; i < n; i++) {
		sum += input[i]-'0'; //atoi함수 사용하면 안됨
	}
	printf("%d", sum);

	return 0;
}