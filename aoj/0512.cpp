#include <iostream>
#include <string>
using namespace std;

int main() {
	string input; cin >> input;
	for (int i=0; i<input.length(); i++) {
		input[i] -= 3;
		if (input[i] < 'A') input[i] += 26;
	}
	cout << input << endl;
}
