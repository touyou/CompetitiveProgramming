/*wa*/
#include <iostream>
using namespace std;
int main() {
	int n,m;
	while (cin>>n>>m&&n!=0&&m!=0) {
		int min=2147483648;
		for (int i=0; i<m; i++) {
			int x,y,c;cin>>x>>y>>c;
			if (min>c) min=c;
		}
		cout << min << endl;
	}
}
