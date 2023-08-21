// 문제 5. 이진수 정렬
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int main() {
	int N, K, a;
	pair<int,int> num[500000]{};
	cin >> N >> K;
	for(int i=0;i<N;i++) {
		cin >> a;
		num[i].second = a;
		bitset<21> b(a);
		num[i].first = b.count();
	}
	sort(num,num+N,greater<>());
	cout << num[K-1].second;
	return 0;
}