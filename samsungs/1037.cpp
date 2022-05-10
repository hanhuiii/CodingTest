#include <iostream>

using namespace std;

int main() {
	int num;
	int min = 1000000;
	int max = 2;
	cin >> num;
	int n;
	for (int i = 0; i < num; i++) {
		cin >> n;
		if (n > max) {
			max = n;
		}
		if (n < min) {
			min = n;
		}
	}

	cout << max * min << '\n';


	return 0;

}