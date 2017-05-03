#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
void solve(string str) {
	ll ans=0;
	for (int i=0; i<str.length(); i++) {
		if (isalpha(str[i])) ans += (i+1)*(str[i]-'A'+1);
	}
	printf("%lld\n",ans);
}

int main() {
	string str;
	while (getline(cin,str)&&str!="#") {
		solve(str);
	}
}
