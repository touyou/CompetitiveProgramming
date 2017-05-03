#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
string dfs(string str) {
	int res = 0;
	if (str.length() == 1) return str;
	for (int i=0; i<str.length(); i++) {
		res += str[i] - '0';
	}
	stringstream ss;
	ss << res;
	return dfs(ss.str());
}
int main() {
	string num;
	while (cin>>num) {
		if (num == "0") break;
		cout << dfs(num) << endl;
	}
}