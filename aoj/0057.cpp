#include <iostream>
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		int l[10001];
		l[0] = 2;
		for (int i=1;i<n;i++) {
			l[i]=l[i-1]+i+1;
		}
		cout << l[n-1] << endl;
	}
}
