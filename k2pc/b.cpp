#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[10], r[7];
string empty, c[100];
int main() {
  cin>>n;
  for (int i=0; i<10; i++) cin>>a[i];
  for (int i=0; i<n; i++) {
	cin>>c[i];
  }
  memset(r, 0, sizeof(r));
  for (int i=0; i<7; i++) {
	bool flag=false;
	int cnt=0;
	for (int j=0; j<n; j++) {
	  if (!flag&&c[j][i]=='X') {
		flag=true;
		cnt++;
	  } else if (c[j][i]=='X') {
		cnt++;
	  } else if (flag) {
		flag=false;
		r[i]=max(r[i], cnt);
		cnt=0;
	  }
	}
	r[i]=max(r[i], cnt);
	// cout<<r[i]<<endl;
  }
  sort(a, a+10);
  sort(r, r+7);
  bool flag=true;
  for (int i=0; i<7; i++) {
	if (a[9-i]<r[6-i]) {
	  // printf("%d %d %d\n",a[10-i],r[7-i],i);
	  flag=false;
	}
  }
  if (flag) puts("YES");
  else puts("NO");
}
