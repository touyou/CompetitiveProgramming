#include <iostream>
#include <vector>
using namespace std;
string haab[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
string tzo[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int found(string mon) {
	for (int i=0; i<19; i++) {
		if (haab[i]==mon) return i;
	}
}
int main() {
	int n; cin >> n;
	int day, year;
	string mon;
	vector<int> aday, ayear;
	vector<string> amon;
	for (int ix=0; ix<n; ix++) {
		string t; cin >> day >> t >> mon >> year;
		int past = year*365+found(mon)*20+day;
		ayear.push_back(past/260);
		amon.push_back(tzo[past%20]);
		aday.push_back(past%13+1);
	}
	cout << n << endl;
	for (int i=0; i<n; i++) cout << aday[i] << " " << amon[i] << " " << ayear[i] << endl;
}
