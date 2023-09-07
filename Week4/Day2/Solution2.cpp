// 문제 17. 통신망 분석
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	const int MAX = 100001;
	int N, M, u, v, num = 0;
	vector<int> G[MAX];
	int lineNum[MAX]{}, computerNum[MAX]{}, minComputer[MAX]{}, computerCpnt[MAX]{};
	bool visited[MAX]{};
	cin >> N >> M;
	for(int i=1;i<=M;i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=N;i++) {
		if(!visited[i]) {
			visited[i] = 1;
			computerCpnt[i] = num;
			computerNum[num]++;
			minComputer[num] = i;
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int x = q.front();
				q.pop();
				for(int k : G[x]) {
					lineNum[num]++;
					if(!visited[k]) {
						visited[k] = 1;
						computerCpnt[k] = num;
						computerNum[num]++;
						q.push(k);
					}
				}
			}
			lineNum[num] /= 2;
			num++;
		}
	}
	int ans = 0;
	for(int i=1;i<num;i++) {
		if (lineNum[ans] * computerNum[i] < lineNum[i] * computerNum[ans]) ans = i;
		else if (lineNum[ans] * computerNum[i] == lineNum[i] * computerNum[ans]) {
			if (computerNum[i] < computerNum[ans]) ans = i;
		}
	}
	for(int i=1;i<=N;i++) if (computerCpnt[i] == ans) cout << i << " ";
	return 0;
}