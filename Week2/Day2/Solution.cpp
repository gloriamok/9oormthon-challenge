// 문제 7. 구름 찾기 깃발
#include <iostream>
using namespace std;

int N, K, flagKNum = 0;
bool game[1000][1000]{};
int dx[8] = {1,-1,0,0,1,-1,1,-1}, dy[8] = {0,0,1,-1,1,-1,-1,1};


void findFlagK(int x, int y){
	int cnt = 0;
	for(int k=0;k<8;k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && game[nx][ny]) cnt++;
	}
	if (cnt == K) flagKNum++;
}

int main() {
	cin >> N >> K;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin >> game[i][j];
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if (game[i][j] == 0) findFlagK(i,j);
		}
	}
	cout << flagKNum;
}