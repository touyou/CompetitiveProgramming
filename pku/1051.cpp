#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#define FOR(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
using namespace std;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";
string morse[30] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","..--",".-.-","---.","----"};

char encode(string m) {
	int res;
	FOR(i,0,30) {
		if (morse[i]==m) {
			res = i;
			break;
		}
	}
	return alpha[res];
}

int main() {
	int t; cin >> t;
	FOR(ix, 1, t+1) {
		string ms = "", num = "";
		string input; cin >> input;
		FOR(i,0,input.length()) {
			if (isalpha(input[i])) {
				string tmp = morse[input[i]-'A'];
				ms += tmp; num += (char)tmp.length();
			} else {
				switch (input[i]) {
					case '_':
						ms += morse[26];
						num += (char)morse[26].length();
						break;
					case ',':
						ms += morse[27];
						num += (char)morse[27].length();
						break;
					case '.':
						ms += morse[28];
						num += (char)morse[28].length();
						break;
					case '?':
						ms += morse[29];
						num += (char)morse[29].length();
						break;
				}
			}
		}
		reverse(num.begin(), num.end());
		int ad = 0; string res = "";
		FOR(i,0,num.length()) {
			res += encode(ms.substr(ad, (int)num[i]));
			ad += (int)num[i];
		}
		cout << ix << ": " << res << endl;
	}
}
