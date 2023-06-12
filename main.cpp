#include<iostream>
#include<vector>

using namespace std;


int main() {
	// O(n^2) should be fast for n <= 200
	int n;
	cin >> n;
	std::vector<short int> x(n);
	std::vector<short int> y(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		bool s[4] = {false};
		for (int j = 0; j < n && !(s[0] && s[1] && s[2] && s[3]); j++) {
			if (j == i) continue;
			if (x[j] == x[i]) {
				if (y[i] > y[j]) s[0] = true;
				if (y[i] < y[j]) s[1] = true;
			}

			if (y[i] == y[j]) {
				if (x[i] > x[j]) s[2] = true;
				if (x[i] < x[j]) s[3] = true;
			}
		}
		num += (s[0] && s[1] && s[2] && s[3]);
	}

	cout << num;
}
