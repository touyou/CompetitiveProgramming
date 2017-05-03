#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int T; cin>>T;
	string s1,s2,rs2;
	for (int ix=0; ix<T; ix++) {
		cin>>s1>>s2;
		rs2=s2; reverse(rs2.begin(), rs2.end());
		bool flag=false;
		int t=0;
		for (int i=0; i<s1.length(); i++) if (s1[i]==s2[t]) t++;
		if (t==s2.length()) flag=true;
		t=0;
		for (int i=0; i<s1.length(); i++) if (s1[i]==rs2[t]) t++;
		if (flag||t==rs2.length()) printf("YES\n");
		else printf("NO\n");
	}
}
