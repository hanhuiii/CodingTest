#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		int temp = str[i];
		str[i] = str[len - i-1];
		str[len - i-1] = temp;
	}
}


int main() {
	char a[10001] = { 0, };
	char b[10001] = { 0, };
	char ans[10002] = { 0, };
	scanf("%s %s", a, b);
	reverse(a);
	reverse(b);
	
	int len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
	int carry = 0;
	for (int i = 0; i < len; i++) {
		int res = a[i]-'0' + b[i]-'0' + carry;
		while (res < 0)
			res += '0';
		if (res > 9)
			carry = 1;
		else
			carry = 0;
		ans[i] = res % 10+'0';
	}
	if (carry == 1)
		ans[len] = '1';
	reverse(ans);
	printf("%s", ans);
	return 0;
}