#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int num;
		char input[20];
		scanf("%d", &num);
		scanf("%s", input);
		for (int k = 0; k < strlen(input); k++) {
			for (int j = 0; j < num; j++) {
				printf("%c", input[k]);
			}
		}
		printf("\n");
	}
	return 0;
}