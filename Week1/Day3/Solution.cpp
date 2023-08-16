// 문제 3. 합 계산기
#include <iostream>
using namespace std;
int main() {
	int T, a, b, sum = 0;
	char operationSymbol;
	cin >> T;
	for (int i=1;i<=T;i++) {
		cin >> a >> operationSymbol >> b;
		if (operationSymbol == '+') sum += (a+b);
		else if (operationSymbol == '-') sum += (a-b);
		else if (operationSymbol == '*') sum += (a*b);
		else sum += (a/b);
	}
	cout << sum;
	return 0;
}