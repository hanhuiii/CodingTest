#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	char input[15];
	int num, sum = 0;
	scanf("%s", input);
	for(int j=0;j<15;j++){
		for (int i = 0; i < strlen(input); i++) {
			if ((int)input[i] == j + (int)'A') {
					num = j / 3 + 3;
				sum += num;
			}
		}
	}
	for (int j = 15; j < 19; j++) {
		for (int i = 0; i < strlen(input); i++) {
			if ((int)input[i] == j + (int)'A') {
				sum += 8;
			}
		}
	}
	for (int j = 19; j < 22; j++) {
		for (int i = 0; i < strlen(input); i++) {
			if ((int)input[i] == j + (int)'A') {
				sum += 9;
			}
		}
	}
	for (int j = 22; j < 26; j++) {
		for (int i = 0; i < strlen(input); i++) {
			if ((int)input[i] == j + (int)'A') {
				sum += 10;
			}
		}
	}
	printf("%d", sum);
	return 0;
}