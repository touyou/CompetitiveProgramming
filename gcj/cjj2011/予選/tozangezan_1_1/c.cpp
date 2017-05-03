#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
long long d[100];
long long e[100];
int f[100];
long long all[100];
pair<int,int > dat[100];//‚±‚ê‚Í‰¿’lEí—Ş”Ô†
int main(){
	int a;
	scanf("%d",&a);
	for(int T=0;T<a;T++){
		int b,c;
		scanf("%d%d",&b,&c);
		for(int i=0;i<b;i++){
			scanf("%lld%lld%d",d+i,e+i,f+i);
			dat[i]=make_pair(-f[i],i);
		}
		long long ret=0;
		std::sort(dat,dat+b);
		for(int i=0;i<b;i++){
			int val=-dat[i].first;
			int at=dat[i].second;
			if(e[at]==0)continue;
			long long begin=max(1LL,e[at]-d[at]+1);
			long long end=e[at];
		//	printf("%d %lld %lld\n",val,begin,end);
			ret+=(end-begin+1)*val;
			for(int j=0;j<b;j++){
				if(e[j]>end){
					e[j]-=end-begin+1;
				}else{
					e[j]=min(e[j],begin-1);
				}
			}
		}
		printf("Case #%d: %lld\n",T+1,ret);
	}
}