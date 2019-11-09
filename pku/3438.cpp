#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	int t; cin>>t;
	for (int ix=0; ix<t; ix++) {
		string in; cin>>in;
		char tm=in[0];
		int cnt=1;
		string ans="", tmp;
		for (int i=1; i<in.length(); i++) {
			if (tm==in[i]) {
				cnt++;
				continue;
			}
			stringstream ss; ss<<cnt;
			tmp=ss.str();
			ans+=tmp+tm;
			tm=in[i]; cnt=1;
		}
		stringstream ss; ss<<cnt;
		tmp=ss.str();
		ans+=tmp+tm;
		cout<<ans<<endl;
	}
}
