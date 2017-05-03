#include <cstdio>
int main() {
	double x1,x2,xq,y1,y2,yq;
	while (scanf("%lf,%lf,%lf,%lf,%lf,%lf",&x1,&y1,&x2,&y2,&xq,&yq)!=EOF) {
		double xr,yr;
		double m = (y2-y1)/(x2-x1)
		double c = -m*xq+yq;
		xr = (c-yq-xq/m)/(m-1/m);
		yr = -1/m*(xr-xq)+yq;
		printf("%.6f %.6f\n",xr,yr);
	}
}
