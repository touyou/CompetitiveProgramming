#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define EPS 1e-10
using namespace std;
double add(double a, double b) {
    if (abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return abs(a+b);
}
struct P {
    double x, y;
    P () {}
    P (double x, double y) : x(x), y(y) {}
    P operator + (P p) {
        return P(add(x,p.x),add(y,p.y));
    }
    P operator - (P p) {
        return P(add(x,-p.x),add(y,-p.y));
    }
    P operator * (P p) {
        return P(x*p.x,y*p.y);
    }
    P operator / (double n) {
        return P(x/n, y/n);
    }
    double dot(P p) {
        return add(x*p.y,y*p.x);
    }
    double det(P p) {
        return add(x*p.y,-y*p.x);
    }
};
P A[100000], B[100000];
int an, bn;
int convex_contains(P p) {
    P g=(A[0]+A[an/3]+A[2*an/3])/3.0;
    int a=0, b=an;
    while (a+1<b) {
        int c=(a+b)/2;
        if ((A[a]-g).det(A[c]-g)>0) {
            if ((A[a]-g).det(p-g)>0&&(A[c]-g).det(p-g)<0) b=c;
            else a=c;
        } else {
            if ((A[a]-g).det(p-g)<0&&(A[c]-g).det(p-g)>0) a=c;
            else b=c;
        }
    }
    b %= an;
    if ((A[a]-p).det(A[b]-p)<0) return 0;
    if ((A[a]-p).det(A[b]-p)>0) return 2;
    return 1;
}
int main() {
    scanf("%d",&an);
    for (int i=0; i<an; i++) {
        int x, y; scanf("%d%d",&x,&y);
        A[i]=P((double)x,(double)y);
    }
    scanf("%d",&bn);
    for (int i=0; i<bn; i++) {
        int x, y; scanf("%d%d",&x,&y);
        B[i]=P((double)x,(double)y);
    }
    for (int i=0; i<bn; i++) {
        if (convex_contains(B[i])==0) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}
