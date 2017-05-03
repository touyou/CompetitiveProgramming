#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string calc(string l, string s) {
  reverse(s.begin(), s.end());
  int temp = 0;
  string ret = "";
  for (int i=0; i<4; i++) {
	int a = l[i]-'0', b = s[i]-'0';
	int res = a-b-temp;
	if (res<0) {
	  res+=10;
	  temp=1;
	} else {
	  temp=0;
	}
	ret+=(res+'0');
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
int main() {
  string n;
  while (cin>>n) {
	if (n=="0000") break;
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	bool flag=true;
	for (int i=0; i<4; i++) {
	  cnt[n[i]-'0']++;
	  if (cnt[n[i]-'0']==4) flag=false;
	}
	if (!flag) {
	  puts("NA");
	  continue;
	}
	//cout<<calc("2210","2210")<<endl;
	int res = 0;
	while (n!="6174"&&res<10) {
	  res++;
	  string l = n;
	  string s = n;
	  sort(l.begin(), l.end());
	  sort(s.begin(), s.end());
	  n = calc(l, s);
	  //cout<<l<<s<<endl;
	  //cout<<n << " " << calc(l,s)<<endl;
	}
	printf("%d\n",res);
  }
}
