// 문제 8. 통증
#include <iostream>
using namespace std;
int main() {
	int N, item[3] = {14, 7, 1}, cnt = 0;
	cin >> N;
	for(int i=0;i<3;i++) {
		if (N >= item[i]) {
			cnt += (N / item[i]);
			N -= ((N / item[i]) * item[i]);
		}
	}
	cout << cnt;
}