#include <iostream>

using namespace std;

int g(int num) {
	
	unsigned long long int sum = 0;
	for (int i = 1; i <= num; i++) {
		sum += (num / i) * i;
	}
	return sum;

}


int main() {
	int n;
	cin >> n;
	int num;
	unsigned long long int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cout << g(num) << '\n';
	}
	return 0;
}