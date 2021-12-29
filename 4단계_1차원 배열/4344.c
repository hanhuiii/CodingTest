#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int main() {
	int n, s;
	float avg;
	int score[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);
		int up = 0;
		int sum = 0;
		
		for (int j = 0; j < s; j++) {
			scanf("%d", &score[j]);
			sum += score[j];
		}
		
		avg = sum / s;
		for (int j = 0; j < s; j++) {
			if (score[j] > avg)
				up++;
		}
		float range = ((double)up / (double)s) * 100;
		printf("%.3f%%\n", range);//%Ãâ·Â
		
	}
	return 0;
}