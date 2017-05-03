#include <cstdio>
using namespace std;
int main() {
	int amt=0,qut=0,cnt=0,a,b;
	while (scanf("%d,%d",&a,&b)!=EOF) {
		amt += a*b;
		qut += b;
		cnt++;
	}
	int res = qut/cnt;
	double dec = (double)qut/(double)cnt-res;
	if (dec>=0.5) res+=1;
	printf("%d\n%d\n",amt,res);
}
