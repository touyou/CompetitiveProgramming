#include <iostream>
#include <string>

using namespace std;

int main() {
	int N; cin >> N;
	for (int i=0; i<N; i++) {
		string a, b;
		cin >> a >> b;
		int sum, ret=0;
		if (a.length() < b.length()) swap(a,b);
		int l = b.length()-1;
		for (int i=a.length()-1; i>=0; i--) {
			if (l >= 0) {
				sum = (a[i]-48)+(b[l]-48)+ret;
				l--;
			} else {
				sum = (a[i]-48)+ret;
			}
			if (sum>=10) {
				ret = 1;
				sum -= 10;
			} else {
				ret = 0;
			}
			a[i] = sum+48;
		}
		if (ret != 0) {
			a.insert(a.begin(), ret+48);
		}
		if (a.length() > 80) cout << "overflow" << endl;
		else cout << a << endl;
	}
	return 0;
}
