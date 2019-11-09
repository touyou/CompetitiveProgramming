#include <cstdio>
int main() {
	int x1,x2,x3,x4,y1,y2,y3,y4;
	scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	int b1=y2-y1, b2=x2-x1, b3=y4-y3, b4=x4-x3;
	double p1,p2;
	if (b1==0||b2==0) p1=0;
	else p1=(double)b1/(double)b2;
	if (b3==0||b4==0) p2=0;
	else p2=(double)b3/(double)b4;
	if (p1==p2) printf("parallel\n");
	else printf("not parallel\n");
}