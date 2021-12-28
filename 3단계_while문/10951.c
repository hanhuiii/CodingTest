#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int a, b;
	
	while (scanf("%d %d", &a, &b)!=EOF) { //출력초과를 해결하기 위해 EOF사용
		//EOF = End-Of-File의 약자로 파일의끝을 표현하기 위한 상수, -1
		if (a > 0 && b < 10) {
			printf("%d\n", a + b);
		}
	}
	return 0;
}