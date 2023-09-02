// 문제 14. 작은 노드
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int N, M, K, u, v;
	cin >> N >> M >> K;
	vector<int> graph[2001];
	for(int i=1;i<=M;i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=N;i++) {
		sort(graph[i].begin(),graph[i].end());
	}
	bool visited[2001]{};
	visited[K] = 1;
	int visitedNodeNum = 1, lastVisitedNode = K;
	queue<int> q;
	q.push(K);
	while(!q.empty()) {
		int startNode = q.front();
		q.pop();
		for(int node : graph[startNode]) {
			if (!visited[node]) {
				visited[node] = 1;
				visitedNodeNum++;
				lastVisitedNode = node;
				q.push(node);
				break;
			}
		}
	}
	cout << visitedNodeNum << " " << lastVisitedNode;
}