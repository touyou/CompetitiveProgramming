#include <iostream>
using namespace std;
int main() {
	string str;
	while (cin>>str) {
		int joi=0,ioi=0;
		for (int i=0; i<str.length(); i++) {
			if (str[i]=='J'&&i+2<str.length()&&str[i+1]=='O'&&str[i+2]=='I') {
				joi++;
			} else if (str[i]=='I'&&i+2<str.length()&&str[i+1]=='O'&&str[i+2]=='I') {
				ioi++;
			}
		}
		cout << joi << endl;
		cout << ioi << endl;
	}
}
