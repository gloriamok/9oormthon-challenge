// 문제 1. 운동 중독 플레이어
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float W, R;
	cin >> W >> R;
	cout << (int)floor(W*(1+(R/30)));
	return 0;
}
