#include <iostream>

using namespace std;


int main() {
	int num;
	cin >> num;
	unsigned long long int sum = 0;
	for (int i = 1; i <= num; i++) {

		sum += (num / i) * i;
	}

	cout << sum << '\n';

	return 0;
}