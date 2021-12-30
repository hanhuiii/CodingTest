#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	char input[100];
	
	scanf("%s", input);
	int count = strlen(input);

	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '=') {
			if (input[i - 1] == 'c')
				count--;
			if (input[i - 1] == 's')
				count--;
			if (input[i - 1] == 'z') {
				count--;
				if (input[i - 2] == 'd')
					count--;
			}
		}
		if (input[i] == '-') {
			if (input[i - 1] == 'c')
				count--;
			if (input[i - 1] == 'd')
				count--;
		}
		if (input[i] == 'j') {
			if (input[i - 1] == 'l')
				count--;
			if (input[i - 1] == 'n')
				count--;
		}
	}

	printf("%d", count );

	return 0;
}