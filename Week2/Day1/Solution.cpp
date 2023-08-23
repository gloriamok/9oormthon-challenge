// 문제 6. 문자열 나누기
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main() {
	int N, maxScore = 0;
	string S;
	cin >> N >> S;
	set<string> temp;
	for(int i=0;i<N;i++) {
		string sub = "";
		for(int j=i;j<N;j++) {
			sub += S[j];
			if ((int)sub.length() <= N - 2) temp.insert(sub);
		}
	}
	vector<string> P;
	for(string t : temp) P.push_back(t);
	map<string, int> score;
	for(int i=0;i<P.size();i++) {
		score[P[i]] = i+1;
	}
	for (int L = 1; L < N; L++) {
		int i = score[S.substr(0, L)];
		for (int R = L + 1; R < N; R++) {
			int j = score[S.substr(L, R - L)];
			int k = score[S.substr(R, N - R)];
			maxScore = max(maxScore, i + j + k);
		}
	}
	cout << maxScore;
}