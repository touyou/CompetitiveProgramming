#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
void outp(int s) {
	if (s%3==1) printf("1\n");
	else if (s%3==2) printf("2\n");
	else printf("3\n");
}
int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i=0; i<k; i++) {
		int a, b; scanf("%d%d",&a,&b);
		int x1=b, x2=abs(n-b)+1, y1=a, y2=abs(n-a)+1;
		if (x1>x2) swap(x1,x2);
		if (y1>y2) swap(y1,y2);
		if (x1<=a&&a<=x2) outp(x1);
		else if (y1<=b&&b<=y2) outp(y1);
	}
}