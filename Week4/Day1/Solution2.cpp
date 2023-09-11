// 문제 16. 연합
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, M, u, v, unionNum = 0;
	cin >> N >> M;
	bool island[2001][2001]{}, visited[2001]{};
	for(int i=1;i<=M;i++) {
		cin >> u >> v;
		island[u][v] = 1;
	}
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
					if (!visited[j] && island[x][j] && island[j][x]) {
						visited[j] = 1;
						q.push(j);
					}
				}
			}
		}
	}
	cout << unionNum;
}