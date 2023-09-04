// 문제 16. 연합
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, s, e, unionNum = 0;
bool island[2001][2001]{}, visited[2001]{};

void bfs() {
	for(int i=1;i<=N;i++) {
		if (!visited[i]) {
			visited[i] = 1;
			unionNum++;
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int x = q.front();
				q.pop();
				for(int j=1;j<=N;j++) {
					if (island[x][j] && !visited[j] && island[j][x]) {
						visited[j] = 1;
						q.push(j);
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for(int i=1;i<=M;i++) {
		cin >> s >> e;
		island[s][e] = 1;
	}
	bfs();
	cout << unionNum;
	return 0;
}