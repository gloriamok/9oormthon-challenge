// 문제 11. 통증 (2)
#include <iostream>
using namespace std;


int main() {
	int N, A, B, pain[1000001]{};
	cin >> N >> A >> B;
	fill_n(pain,N+1,1000001);
	pain[0] = 0;
	for(int i=1;i<=N;i++) {
		if (i-A >= 0) pain[i] = min(pain[i],pain[i-A] + 1);
		if (i-B >= 0) pain[i] = min(pain[i],pain[i-B] + 1);
	}
	if (pain[N] >= 1000001) cout << -1;
	else cout << pain[N];
}