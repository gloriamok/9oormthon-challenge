// 문제 17. 통신망 분석
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Component{
	int lineNum;
	int computerNum;
	int minComputer;
};

bool cmp(Component a, Component b) {
	if (a.lineNum * b.computerNum != a.computerNum * b.lineNum) return a.lineNum * b.computerNum > a.computerNum * b.lineNum;
	else if (a.computerNum != b.computerNum) return a.computerNum < b.computerNum;
	else return a.minComputer < b.minComputer;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	const int MAX = 100001;
	int N, M, u, v, cpntNum = 0;
	vector<int> G[MAX];
	Component cpnt[MAX]{};
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
			cpnt[cpntNum].computerNum++;
			cpnt[cpntNum].minComputer = i;
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int x = q.front();
				q.pop();
				for(int k : G[x]) {
					cpnt[cpntNum].lineNum++;
					if(!visited[k]) {
						visited[k] = 1;
						cpnt[cpntNum].computerNum++;
						q.push(k);
					}
				}
			}
			cpnt[cpntNum].lineNum /= 2;
			cpntNum++;
		}
	}
	sort(cpnt,cpnt+cpntNum,cmp);
	vector<int> selectedCpnt;
	selectedCpnt.push_back(cpnt[0].minComputer);
	fill_n(visited,N+1,0);
	visited[cpnt[0].minComputer] = 1;
	queue<int> q;
	q.push(cpnt[0].minComputer);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int k : G[x]) {
			if(!visited[k]) {
				visited[k] = 1;
				selectedCpnt.push_back(k);
				q.push(k);
			}
		}
	}
	sort(selectedCpnt.begin(),selectedCpnt.end());
	for(int i=0;i<cpnt[0].computerNum;i++) cout << selectedCpnt[i] << " ";
	return 0;
}