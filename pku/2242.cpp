#include <cstdio>
#include <cmath>
#define pi 3.141592653589793
double line(double a, double b, double c, double d) {
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main() {
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF) {
        double a=line(x1,y1,x2,y2);
        double b=line(x2,y2,x3,y3);
        double c=line(x3,y3,x1,y1);
        double r=a*b*c/sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
        printf("%.2f\n",2*r*pi);
    }
}