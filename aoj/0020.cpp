#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string str; getline(cin, str);
	for (int i=0; i<str.length(); i++) {
		if (str[i] != ' ' && str[i] != '.') {
			str[i] = toupper(str[i]);
		}
	}
	cout << str << endl;
	return 0;
}
