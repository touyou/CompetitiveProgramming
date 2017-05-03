/*tle*/
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int r,c,q;
	while (scanf("%d%d%d",&r,&c,&q)&&r!=0&&c!=0&&q!=0) {
		vector<int> m(c);
		vector<vector<int> > maps(r,m);
		for (int i=0; i<r; i++) for (int j=0; j<c; j++) scanf("%d",&maps[i][j]);
		for (int i=0; i<q; i++) {
			int r1,c1,r2,c2; scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			int min=2147483647;
			for (int y=r1; y<=r2; y++) {
				for (int x=c1; x<=c2; x++) {
					if (min>maps[y][x]) min = maps[y][x];
					if (min==0) break;
				}
				if (min==0) break;
			}
			printf("%d\n",min);
		}
	}
}
