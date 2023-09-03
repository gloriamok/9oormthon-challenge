// 문제 15. 과일 구매
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, K;
	long int maxC = 0;
	cin >> N >> K;
	pair<int,int> fruits[1000]{}; // pair<C/P, P> == <과일 한 조각에 얻을 수 있는 포만감, 과일 하나의 가격>
	for(int i=0;i<N;i++) {
		// cin >> P >> C
		cin >> fruits[i].second >> fruits[i].first;
		// C/P
		fruits[i].first /= fruits[i].second;
	}
	sort(fruits,fruits+N,greater<>());
	for(int i=0;i<N&&K>0;i++) {
		int p = fruits[i].second;
		if (p > K) p = K;
		maxC += fruits[i].first*p;
		K -= p;
	}
	cout << maxC;
	return 0;
}