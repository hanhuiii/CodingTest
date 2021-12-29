#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int main() {
	int n, score, sum=0;
	char arr[80];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr);
		score = 1;
		sum = 0;
		for (int j = 0; j < strlen(arr); j++) {
			if (arr[j] == 'O') {
				sum += score;
				score++;
			}
			else if (arr[j] == 'X') {
				score = 1;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}