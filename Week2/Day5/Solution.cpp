// 문제 10. GameJam
#include <iostream>
#include <string>
using namespace std;

int N, gr, gc, pr, pc, count[200][200]{}, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
char command[200][200]{};

int simulation(int x, int y) {
	bool visited[200][200]{};
	visited[x][y] = 1;
	int score = 1;
	while(1) {
		int cnt = count[x][y];
		int dir;
		switch(command[x][y]) {
			case 'D':
				dir = 0;
				break;
			case 'U':
				dir = 1;
				break;
			case 'R':
				dir = 2;
				break;
			default:
				dir = 3;
				break;
		}
		while(cnt--){
			x += dx[dir];
			y += dy[dir];
			if (x >= N) x -= N;
			else if (x < 0) x += N;
			if (y >= N) y -= N;
			else if (y < 0) y += N;
			if (!visited[x][y]) {
				visited[x][y] = 1;
				score++;
			}
			else return score;
		}
	}
	return score;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> gr >> gc >> pr >> pc;
	gr--;
	gc--;
	pr--;
	pc--;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> count[i][j] >> command[i][j];
	int gs = simulation(gr,gc), ps = simulation(pr,pc);
	if (gs > ps) cout << "goorm " << gs;
	else cout << "player " << ps;
}