#include <cstdio>
#include <vector>
using namespace std;
#define PB push_back
int main() {
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)) {
		if (a==0&&b==0&&c==0) break;
		vector<int> part(a+b+c,2);
		vector<vector<int> > set;
		int N; scanf("%d",&N);
		int i,j,k,l;
		for (int cnt=0; cnt<N; cnt++) {
			scanf("%d %d %d %d",&i,&j,&k,&l);
			if (l==1) {
				part[i-1]=part[j-1]=part[k-1]=1;
			} else {
				vector<int> tmp(3);
				tmp[0]=i-1; tmp[1]=j-1; tmp[2]=k-1;
				set.PB(tmp);
			}
		}
		for (int cnt=0; cnt<set.size(); cnt++) {
			int n=part[set[cnt][0]], m=part[set[cnt][1]], p=part[set[cnt][2]];
			if (n==1&&m==1) part[set[cnt][2]]=0;
			if (n==1&&p==1) part[set[cnt][1]]=0;
			if (p==1&&m==1) part[set[cnt][0]]=0;
		}
		for (int cnt=0; cnt<a+b+c; cnt++) printf("%d\n",part[cnt]);
	}
}
