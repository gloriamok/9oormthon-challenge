// 문제 9. 폭탄 구현하기 (2)
#include <iostream>
using namespace std;
int main() {
	int N, K, r, c, dr[5] = {0,1,-1,0,0}, dc[5] = {0,0,0,1,-1}, maxBumb = 0;
	cin >> N >> K;
	char s;
	pair<int,int> ground[201][201]{};
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin >> s;
			if (s == '0') ground[i][j].second = 0;
			else if (s == '#') ground[i][j].second = 1;
			else ground[i][j].second = 2;
		}
	}
	for(int i=1;i<=K;i++) {
		cin >> r >> c;
		for(int j=0;j<5;j++) {
			int nr = r + dr[j], nc = c + dc[j];
			if (nr > 0 && nr <= N && nc > 0 && nc <= N && ground[nr][nc].second != 1) {
				if (ground[nr][nc].second == 2) ground[nr][nc].first += 2;
				else ground[nr][nc].first++;
			}
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			maxBumb = max(maxBumb, ground[i][j].first);
		}
	}
	cout << maxBumb;
}