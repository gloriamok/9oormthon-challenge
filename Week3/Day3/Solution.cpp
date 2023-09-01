// 문제 13. 발전기 (2)
#include <iostream>
#include <queue>
using namespace std;

int N, K, houseNum = 0, village[1000][1000]{}, buildings[31]{};
bool visited[1000][1000]{};
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

void bfs() {
	for(int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			if (houseNum == 0) return;
			else if (village[i][j] && !visited[i][j]) {
				int buildingNo = village[i][j];
				visited[i][j] = 1;
				houseNum--;
				int buildingCnt = 1;
				queue<pair<int,int>> q;
				q.push({i,j});
				while(!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for(int k=0;k<4;k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N && village[nx][ny] == buildingNo && !visited[nx][ny]) {
							visited[nx][ny] = 1;
							houseNum--;
							buildingCnt++;
							q.push({nx,ny});
						}
					}
				}
				if (buildingCnt >= K) buildings[buildingNo]++;
			}
		}
	}
}

int main() {
	cin >> N >> K;
	houseNum = N*N;
	for(int i=0;i<N;i++) for (int j=0;j<N;j++) cin >> village[i][j];
	bfs();
	int maxBuildings = 0, maxBuildingIdx;
	for(int i=1;i<=30;i++) {
		if (buildings[i] >= maxBuildings) {
			maxBuildings = buildings[i];
			maxBuildingIdx = i;
		}
	}
	cout << maxBuildingIdx;
	return 0;
}