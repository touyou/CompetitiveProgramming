#include <iostream>
using namespace std;
typedef long long ll;
ll comb(int a, int b) {
	if (a<b) return 0;
	return a-b+1;
}
int main() {
	int n, m;
	string str;
	while (cin>>n&&n!=0) {
		cin>>m>>str;
		ll res=0;
		int cnt=0;
		for (int i=0; i<m-1; i++) {
			if (str[i]=='I') {
				if (str[i+1]=='O'&&str[i+2]=='I') cnt++;
				else {
					res += comb(cnt,n);
					cnt=0;
				}
			}
		}
		if (str[m-3]=='I'&&str[m-2]&&'O'&&str[m-1]=='I') {
			res += comb(cnt,n);
		} else if (str[m-3]=='O') {
			res += comb(cnt,n);
		}
		cout << res << endl;
	}
}