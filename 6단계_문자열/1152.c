#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	char input[1000000];
	int count = 0;
	scanf("%[^\n]s", input);
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == ' ')
			count++;
	}
	if (input[0] == ' ')
		count--;
	if (input[strlen(input) - 1] == ' ')
		count--;
	if (strlen(input) == 0 && input[0] == ' ')
		printf("0");
	else
		printf("%d", count+1);
	return 0;
}