// 문제 18. 중첩 점
#include <bits/stdc++.h>
using namespace std;

const int MAX = 103;
int dp[2][MAX][MAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long N, M, ans = 0;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int y, x;
        char d;
        cin >> y >> x >> d;
        if (d == 'L') for (int k = x; k > 0; --k) dp[0][y][k]++;
        else if (d == 'R') for (int k = x; k <= N; ++k) dp[0][y][k]++;
        else if (d == 'U') for (int k = y; k > 0; --k) dp[1][k][x]++;
        else for (int k = y; k <= N; ++k) dp[1][k][x]++;
    }

    for (int y = 1; y <= N; ++y) for (int x = 1; x <= N; ++x)
        ans += 1LL * dp[0][y][x] * dp[1][y][x];

    cout << ans << '\n';
    return 0;
}