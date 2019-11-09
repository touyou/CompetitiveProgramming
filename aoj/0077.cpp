#include <iostream>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		string res = "";
		for (int i=0; i<str.length(); i++) {
			if (str[i] == '@' && i+2 < str.length()) {
				int n = str[i+1] - '0';
				for (int j=0; j<n; j++) res += str[i+2];
				i+=2;
			} else {
				res += str[i];
			}
		}
		cout << res << endl;
	}
}
