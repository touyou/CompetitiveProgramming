#include <iostream>
using namespace std;
int main() {
	string a, b;
	while (cin>>a>>b) {
		if (a=="0"&&b=="0") break;
		int hit=0, blow=0;
		for (int i=0; i<4; i++) {
			if (a[i]==b[i]) {
				hit++;
			} else {
				for (int j=0; j<4; j++) {
					if (a[i]==b[j]) blow++;
				}
			}
		}
		cout << hit << " " << blow << endl;
	}
}