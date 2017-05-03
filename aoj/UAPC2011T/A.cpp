#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int t; scanf("%d",&t);
	for (int ix=0; ix<t; ix++) {
		int x1,y1,z1,x2,y2,z2;
		scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
		double D = sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
		printf("%.11f\n",D);
	}
}
