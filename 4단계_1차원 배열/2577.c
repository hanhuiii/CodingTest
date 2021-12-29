#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int arr[10] = { 0, };
	int n = a * b * c;
	//if (a, b, c >= 100 && a, b, c < 1000) {
		while (n > 0) {
			int num = n % 10;
			arr[num]++;
			n=n / 10;
			//printf("%d\n", arr[num]);
		}
	//}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}