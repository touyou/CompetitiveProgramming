#include <iostream>
using namespace std;

int main() {
	int a,b;
	char c;
	for (;;) {
		cin >> a >> c >> b;
		if (c == '?') {
			break;
		} else if (c == '+') {
			cout << a+b << endl;
		} else if (c == '-') {
			cout << a-b << endl;
		} else if (c == '*') {
			cout << a*b << endl;
		} else if (c == '/') {
			int ans = (int)a/b;
			cout << ans << endl;
		}
	}
}
