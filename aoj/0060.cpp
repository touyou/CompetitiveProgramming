#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a,b,c;
	while (cin>>a>>b>>c) {
		int sum=a+b;
		vector<int> flag(10,0);
		flag[a-1]=flag[b-1]=flag[c-1]=1;
		int cnt=0;
		for (int i=0; i<20-sum; i++) {
			if (flag[i]==0) {
				cnt++;
			}
		}
		if (cnt/7.0>=0.5) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
