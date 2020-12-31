#include<iostream>
#include<vector>

using namespace std;


int main() {
	int a, b, dCount = 0, answer;
	cin >> a;
	answer = a;

	for (int i = 1; i <= a; i++) {
		vector<int> a;
		dCount = 0;
		if (i > 10) {
			b = i;
			while (b > 0) {
				a.push_back(b % 10);
				b /= 10;
			}

			b = abs( a[0] - a[1]);
			for (int j = 1; j < a.size(); j++) {
				if (abs(a[j] - a[j-1]) != b ) {
					answer--;
					break;
				}
				if (a.size() == 3) {
					if (a[0] == a[2] && a[0] != a[1]) {
						answer--;
						break;
					}
				}
			}
		}
	}
	cout << answer;
}