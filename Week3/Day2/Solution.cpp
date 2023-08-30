// 문제 12. 발전기
#include <iostream>
#include <queue>
using namespace std;

int N, minGenerator = 0, houseNum = 0;
bool village[1000][1000]{}, visited[1000][1000]{};
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

void bfs() {
	for(int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			if (houseNum == 0) return;
			else if (village[i][j] && !visited[i][j]) {
				visited[i][j] = 1;
				houseNum--;
				minGenerator++;
				queue<pair<int,int>> q;
				q.push({i,j});
				while(!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for(int k=0;k<4;k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N && village[nx][ny] && !visited[nx][ny]) {
							visited[nx][ny] = 1;
							houseNum--;
							q.push({nx,ny});
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			cin >> village[i][j];
			if (village[i][j]) houseNum++;
		}
	}
	bfs();
	cout << minGenerator;
	return 0;
}