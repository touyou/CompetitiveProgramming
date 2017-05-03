#include <iostream>
#include <string>

using namespace std;

// 1-31 2-29 3-31 4-30 5-31 6-30 7-31 8-31 9-30 10-31 11-30 12-31

int main() {
	int mon, day;
	int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
	string days[] = {"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};
	while (cin >> mon >> day && mon != 0) {
		int pass=0;
		if (mon==1) {
			cout << days[(day-1)%7] << endl;
			continue;
		}
		for (int i=0; i<mon-1; i++) {
			pass += month[i];
		}
		pass += day;
		cout << days[(pass-1)%7] << endl;
	}
	return 0;
}
