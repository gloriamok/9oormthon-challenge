// 문제 4. 완벽한 햄버거 만들기
#include <iostream>
using namespace std;
int main() {
	int N, k1 = 1, k2, sum = 0;
	bool flag = 0;
	cin >> N;
	for(int i=1;i<=N;i++) {
		cin >> k2;
		if (!flag) {
			if (k2 < k1) flag = 1;
		}
		else {
			if (k2 > k1) {
				cout << 0;
				return 0;
			}
		}
		sum += k2;
		k1 = k2;
	}
	cout << sum;
	return 0;
}