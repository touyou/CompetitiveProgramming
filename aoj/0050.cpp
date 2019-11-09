#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	getline(cin, input);
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'p') {
			if (input[i+1]=='e'&&input[i+2]=='a'&&input[i+3]=='c'&&input[i+4]=='h') {
				input[i]='a'; input[i+1]='p'; input[i+2]='p';
				input[i+3]='l'; input[i+4]='e';
				i += 4;
			}
		} else if (input[i] == 'a') {
			if (input[i+1]=='p'&&input[i+2]=='p'&&input[i+3]=='l'&&input[i+4]=='e') {
				input[i]='p'; input[i+1]='e'; input[i+2]='a';
				input[i+3]='c'; input[i+4]='h';
				i += 4;
			}
		}
	}
	cout << input << endl;
}

