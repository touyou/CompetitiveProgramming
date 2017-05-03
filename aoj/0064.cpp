#include <sstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int add(string s) {
	int num = 0;
	string tmp = "";
	for (int i=0; i<s.length(); i++) {
		if (isdigit(s[i])) {
			tmp += s[i];
		} else if (!tmp.empty()) {
			stringstream ss;
			ss.str(tmp);
			int t; ss >> t;
			num += t;
			tmp = "";
		}
	}
	if (!tmp.empty()) {
		stringstream ss;
		ss.str(tmp);
		int t; ss >> t;
		num += t;
	}
	return num;
}

int main() {
	string s;
	int num=0;
	while (cin>>s) {
		num += add(s);
	}
	cout << num << endl;
}
