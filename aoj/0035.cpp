#include <cstdio>
#include <iostream>
using namespace std;
bool check(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    if (x1!=x2) {
        double m = (y2-y1)/(x2-x1);
        if (y3-y1>m*(x3-x1)&&y4-y1<m*(x4-x1)) return true;
        else if (y3-y1<m*(x3-x1)&&y4-y1>m*(x4-x1)) return true;
        else return false;
    } else {
        if (x3>x1&&x4<x1) return true;
        else if (x3<x1&&x4>x1) return true;
        else return false;
    }
}
int main() {
    double xa,ya,xb,yb,xc,yc,xd,yd;
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd) != EOF) {
        if (check(xa,ya,xc,yc,xb,yb,xd,yd)&&check(xb,yb,xd,yd,xa,ya,xc,yc)) puts("YES");
        else puts("NO");
    }
}
