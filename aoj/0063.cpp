#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str;
	int cnt = 0;
	while (cin>>str) {
		string rev = str;
		reverse(rev.begin(), rev.end());
		if (str == rev) cnt++;
	}
	cout << cnt << endl;
}
