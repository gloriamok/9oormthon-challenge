// 문제 18. 중첩 점
#include <iostream>
using namespace std;

int main() {
	int N, M, y, x, k, dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1}; // 상하좌우
	long int pointNum = 0;
	char d;
	pair<long int, long int> square[101][101]{}; // pair<세로줄, 가로줄>
	cin >> N >> M;
	for(int i=1;i<=M;i++) {
		cin >> y >> x >> d;
		switch(d) {
			case 'U':
				k = 0; break;
			case 'D':
				k = 1; break;
			case 'L':
				k = 2; break;
			case 'R':
				k = 3; break;
		}
		while(y > 0 && y <= N && x > 0 && x <= N) {
			if (k == 0 || k == 1) square[y][x].first++;
			else square[y][x].second++;
			y += dy[k];
			x += dx[k];
		}
	}
	for(int i=1;i<=N;i++) for (int j=1;j<=N;j++) pointNum += (square[i][j].first*square[i][j].second);
	cout << pointNum;
}