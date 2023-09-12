// 문제 20. 연결 요소 제거하기
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int N, K, Q, y, x, di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
char arr[51][51]{}, d;
unordered_map<char,int> m;

bool isGreater(int i, int j, bool visited[][51]) {
	visited[i][j] = 1;
	int num = 1;
	queue<pair<int,int>> q;
	q.push({i,j});
	while(!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for(int k=0;k<4;k++) {
			int ni = i + di[k], nj = j + dj[k];
			if (ni > 0 && ni <= N && nj > 0 && nj <= N && !visited[ni][nj] && arr[ni][nj] == arr[i][j]) {
				visited[ni][nj] = 1;
				num++;
				if (num >= K) return true;
				q.push({ni,nj});
			}
		}
	}
	return false;
}

void deleteLetter(int i, int j) {
	bool visited[51][51]{};
	visited[i][j] = 1;
	int alphabet = arr[i][j];
	arr[i][j] = '.';
	m[arr[i][j]]--;
	queue<pair<int,int>> q;
	q.push({i,j});
	while(!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for(int k=0;k<4;k++) {
			int ni = i + di[k], nj = j + dj[k];
			if (ni > 0 && ni <= N && nj > 0 && nj <= N && !visited[ni][nj] && arr[ni][nj] == alphabet) {
				visited[ni][nj] = 1;
				arr[ni][nj] = '.';
				m[arr[ni][nj]]--;
				q.push({ni,nj});
			}
		}
	}
}

int main() {
	cin >> N >> K >> Q;
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
		cin >> arr[i][j];
		if (arr[i][j] != '.') m[arr[i][j]]++;
	}
	for(int num=1;num<=Q;num++) {
		cin >> y >> x >> d;
		arr[y][x] = d;
		m[arr[y][x]]++;
		bool visited[51][51]{};
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
			if (!visited[i][j] && m[arr[i][j]] >= K) {
				if (isGreater(i,j,visited)) deleteLetter(i,j);
			}
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) cout << arr[i][j];
		cout << "\n";
	}
}