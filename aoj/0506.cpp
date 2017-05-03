#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	string s;
	while (cin >> n && n != 0) {
		cin >> s;
		for (int i=0; i<n; i++) {
			int x=0;
			char ch = s[0];
			string tmp="";
			for (int j=0; j<s.length(); j++) {
				if (ch == s[j]) {
					x++;
				} else {
					stringstream ss; ss<<x;
					string cnt=ss.str();
					tmp+=cnt;
					tmp.push_back(ch);
					ch = s[j];
					x = 1;
				}
			}
			stringstream ss; ss<<x;
			string cnt=ss.str();
			tmp+=cnt;
			tmp.push_back(ch);
			s=tmp;
		}
		cout << s << endl;
	}
}
