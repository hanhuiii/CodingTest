#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	char input[100] = {0 };
	scanf("%s", input);
	int alpha[26] = {0, };
	for (int a = 0; a < 26; a++) {
		alpha[a] = -1;
	}
	for (int i = 0; i < strlen(input); i++) {
		for (int a = 0; a < 26; a++) {
			if ((int)input[i] == a + (int)'a'&&alpha[a]==-1)
				alpha[a] = i ;
		}
	}
	for (int a = 0; a < 26; a++) {
		printf("%d ", alpha[a]);
	}
	return 0;
}