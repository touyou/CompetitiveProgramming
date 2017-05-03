#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		int i=0;
		if (isalpha(str[i])) {
			bool flag=false;
			while (i<str.length()) {
				if (isdigit(str[i])) {
					flag=true;
				}
				i++;
			}
			if (flag) cout << "_HYBRID";
			else cout << "_WORD";
		} else if (isdigit(str[i])) {
			bool flag=false;
			while (i<str.length()) {
				if (isalpha(str[i])) {
					flag=true;
				}
				i++;
			}
			if (flag) cout << "_HYBRID";
			else cout << "_DIGIT";
		}
	}
	cout << endl;
}
