#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	char input[1000000];
	int max = -1;
	int a, i, j, n=0;

	scanf("%s", input);

	int alpha[26] = { 0, };
	
	for (j = 0; j < 26; j++) {
		for (i = 0; i < strlen(input); i++) {
			if ((int)input[i] == j + (int)'a') {
				alpha[j]++;
			}
		}
	}
	for (j = 0; j < 26; j++) {
		for (i = 0; i < strlen(input); i++) {
			if ((int)input[i] == j + (int)'A') {
					alpha[j]++;
				
			}
		}
	}
	for (i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			a = i;
		}
	}
	for (i = 0; i < 26; i++) {
		if (alpha[i] == max) {
			n++;	
		}
	}
	if (n == 1)
		printf("%c", 'A' + a);
	else
		printf("?");

	return 0;
}