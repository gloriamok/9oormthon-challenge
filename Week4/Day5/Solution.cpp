// 문제 20. 연결 요소 제거하기
#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int MAX = 55;
char C[MAX][MAX];
int visited[MAX][MAX];

void BFS(int N, int y, int x, int lim) {
    memset(visited, 0, sizeof(visited));
    vector<pii> same;
    queue<pii> Q;
    Q.emplace(y, x);
    visited[y][x] = 1;
    char c = C[y][x];
    while (!Q.empty()) {
        auto [cy, cx] = Q.front(); Q.pop();
        same.emplace_back(cy, cx);
        for (int i = 0; i < 4; ++i) {
            int ny = cy + "2101"[i] - '1', nx = cx + "1012"[i] - '1';
            if (min(ny, nx) < 1 || max(ny, nx) > N || visited[ny][nx] || C[ny][nx] != c) continue;
            visited[ny][nx] = 1;
            Q.emplace(ny, nx);
        }
    }
    
    if (same.size() >= lim) {
        for (auto [cy, cx] : same) {
            C[cy][cx] = '.';
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K, Q;
    cin >> N >> K >> Q;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> C[i][j];

    while (Q--) {
        int y, x;
        char c;
        cin >> y >> x >> c;
        C[y][x] = c;
        BFS(N, y, x, K);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) cout << C[i][j];
        cout << '\n';
    }
    return 0;
}