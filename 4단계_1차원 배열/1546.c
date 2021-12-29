#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int m = -1;
	float sum = 0;
	scanf("%d", &n);
	float* arr = (float*)malloc(sizeof(float) * n);
	
	for (int i = 0; i < n; i++) {
		scanf("%f", &arr[i]);
		if (arr[i] > m) { m = arr[i]; }
	}
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / m * 100;
	}
	
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}
	
	float avg = sum / n;
	printf("%f", avg);
	return 0;
}