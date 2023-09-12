// 문제 20. 연결 요소 제거하기
// 새로 문자를 쓴 위치에서만 그래프 탐색을 시행
// 실행시간을 크게 줄일 수 있음
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, Q, y, x, di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
char arr[51][51]{}, d;

void bfs(int i, int j) {
	bool visited[51][51]{};
	visited[i][j] = 1;
	vector<pair<int,int>> v;
	queue<pair<int,int>> q;
	v.push_back({i,j});
	q.push({i,j});
	while(!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for(int k=0;k<4;k++) {
			int ni = i + di[k], nj = j + dj[k];
			if (ni > 0 && ni <= N && nj > 0 && nj <= N && !visited[ni][nj] && arr[ni][nj] == arr[i][j]) {
				visited[ni][nj] = 1;
				v.push_back({ni,nj});
				q.push({ni,nj});
			}
		}
	}
	if ((int)v.size() >= K)
		for(int i=0;i<(int)v.size();i++) arr[v[i].first][v[i].second] = '.';
}

int main() {
	cin >> N >> K >> Q;
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> arr[i][j];
	for(int num=1;num<=Q;num++) {
		cin >> y >> x >> d;
		arr[y][x] = d;
		bfs(y,x);
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) cout << arr[i][j];
		cout << "\n";
	}
}