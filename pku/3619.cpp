#include <cstdio>
struct cow { int s,t,r; };
int n,k;
cow c;
int main() {
	scanf("%d%d",&n,&k);
	for (int i=0; i<k; i++) {
		scanf("%d%d%d",&c.s,&c.t,&c.r);
		int need=n/c.s;
		if (n%c.s) need++;
		int x=need/c.t;
		int y=need-x*c.t;
		int res=x*(c.t+c.r);
		if (y) res+=y;
		else res-=c.r;
		// printf("%d %d %d ",need,x,y);
		printf("%d\n",res);
	}
}

/*
need->ok
res-> x=need/c.t:=フルで必要とする回数 y=need-x*c.t:=あまりの時間 ⇒ res=x*(c.t+c.r)+y
*/