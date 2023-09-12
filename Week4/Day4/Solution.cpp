// 문제 19. 대체 경로
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, E, u, v, minCityNum;
vector<int> G[1001];

int bfs(int i) {
	if (i == S || i == E) return -1;
	int visited[1001]{};
	visited[i] = 1;
	visited[S] = 1;
	queue<int> q;
	q.push(S);
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		for(int j : G[f]) {
			if (!visited[j]) {
				visited[j] = visited[f] + 1;
				if (j == E) return visited[j];
				q.push(j);
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M >> S >> E;
	for(int i=1;i<=M;i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=N;i++) {
		minCityNum = bfs(i);
		cout << minCityNum << "\n";
	}
}