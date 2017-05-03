#include<stdio.h>
#include<algorithm>
using namespace std;
int e[100];
int f[100];
int main(){
	int a;
	scanf("%d",&a);
	for(int T=0;T<a;T++){
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		int at=d;
		for(int i=0;i<c;i++){
			scanf("%d%d",e+i,f+i);
		}
		for(int i=c-1;i>=0;i--){
			if(at<=f[i]){
				at=e[i]+at-1;
			}else if(at<=e[i]+f[i]-1){
				at-=f[i];
			}
		}
		printf("Case #%d: %d\n",T+1,at);
	}
}