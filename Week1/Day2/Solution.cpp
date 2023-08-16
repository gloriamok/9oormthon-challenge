// 문제 2. 프로젝트 매니징
#include <iostream>
using namespace std;
int main() {
	int N, T, M, c;
	cin >> N >> T >> M;
	for(int i=0;i<N;i++) {
		cin >> c;
		M += c;
	}
	T += (M/60);
	M %= 60;
	T %= 24;
	cout << T << " " << M;
	return 0;
}