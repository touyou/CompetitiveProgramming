 /*
Write a program which reverses a given string str.
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}
