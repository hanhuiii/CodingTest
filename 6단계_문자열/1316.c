#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	int n;
	scanf("%d", &n);
	int group = n;
	char input[100];
	
	for (int i = 0; i < n; i++) {
		scanf("%s", input);
		int alpha[26] = { 0, };
		int m = 0;
		for (int a = 0; a < 26; a++) {
			for (int j = 0; j < strlen(input); j++) {
				if ((int)input[j] == a + (int)'a') {
					if (j == 0 || (input[j] != input[j - 1])) {
						if (alpha[a] != 0)
							m = 1;
						alpha[a]++;
					}
					
				}
			}
		}
		if (m != 0)
			group--;
	}
	
	printf("%d", group);
	return 0;
}