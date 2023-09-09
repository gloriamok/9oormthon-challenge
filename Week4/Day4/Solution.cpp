// 문제 19. 대체 경로
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1004;
int dist[MAX], no[MAX];
vector<int> G[MAX];

int BFS(int S, int E) {
    if (no[S]) return -1;
    memset(dist, 0x3f, sizeof(dist));
    queue<int> Q;
    dist[S] = 1;
    Q.push(S);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int next : G[cur]) {
            if (no[next] || dist[next] <= dist[cur] + 1) continue;
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }
    return (dist[E] > 1E9 ? -1 : dist[E]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, S, E;
    cin >> N >> M >> S >> E;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        no[i] = 1;
        cout << BFS(S, E) << '\n';
        no[i] = 0;
    }
    return 0;
}