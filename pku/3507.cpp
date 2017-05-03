#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a[6];
int main() {
  while (scanf("%d%d%d%d%d%d",a,a+1,a+2,a+3,a+4,a+5)) {
	if (!a[0]&&!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]) break;
	double sum = 0.0;
	sort(a, a+6);
	for (int i=1; i<5; i++) sum += a[i];
	sum /= 4;
	cout<<sum<<endl;
  }
}
