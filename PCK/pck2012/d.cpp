#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define pi 3.1415926535
#define eps 1e-9
using namespace std;
int h,r,hx[100],hy[100],w,a;
int u,m,s,du,dm,ds;
int ux[10],uy[10],mx[10],my[10],sx[10],sy[10];
int ch[100];
double add(double a, double b) {
    if (abs(a+b)<eps*(abs(a)+abs(b))) return 0;
    return a+b;
}
struct P {
    double x,y;
    P(){}
    P(double x, double y) : x(x),y(y) {}
    P operator + (P p) {
        return P(add(x,p.x),add(y,p.y));
    }
    P operator - (P p) {
        return P(add(x,-p.x), add(y, p.y));
    }
    P operator * (double d) {
        return P(x*d,y*d);
    }
    double dot(P p) {
        return add(x*p.x,y*p.y);
    }
    double det(P p) {
        return add(x*p.y,-y*p.x);
    }
};
bool on_seg(P p1, P p2, P q) {
    return (p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}
P intersection(P p1, P p2, P q1, P q2) {
    return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}
bool isin(int x1, int y1, int x2, int y2, int d, int win, int ac) {
    double dist=sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
    if (dist>(double)ac+eps) return false;
    double rad1=(win-(double)d/2)/360.0*pi, rad2=(win+(double)d/2)/360.0*pi;
    P p0 = P(0.0,0.0);
    P p1 = P((double)x1,(double)y1);  // house
    P p2 = P((double)x2,(double)y2);  // flower
    P p3 = P(x2+ac*cos(rad1), y2+ac*sin(rad1));
    P p4 = P(x4=x2+ac*cos(rad2), y2+ac*sin(rad2));
    if (on_seg(p2,p3,p1)||on_seg(p2,p4,p1)) return true;
    P r1 = intersection(p2,p3,p0,p1), r2 = intersection(p2, p4, p0, p1);
    if ((on_seg(p2,p3,r1)&&on_seg(p0,p1,r1))&&(on_seg(p2,p4,r2)&&on_seg(p0,p1,r2))) return false;
    if ((on_seg(p2,p3,r1)&&on_seg(p0,p1,r1))||(on_seg(p2,p4,r2)&&on_seg(p0,p1,r2))) return true;
    return false;
}
int main() {
    while (scanf("%d%d",&h,&r)) {
        if (!h&&!r) break;
        vector<int> res;
        memset(ch, 0, sizeof(ch));

        for (int i=0; i<h; i++) scanf("%d%d",&hx[i],&hy[i]);
        scanf("%d%d%d%d%d%d",&u,&m,&s,&du,&dm,&ds);
        for (int i=0; i<u; i++) scanf("%d%d",&ux[i],&uy[i]);
        for (int i=0; i<m; i++) scanf("%d%d",&mx[i],&my[i]);
        for (int i=0; i<s; i++) scanf("%d%d",&sx[i],&sy[i]);
        for (int ix=0; ix<r; ix++) {
            scanf("%d%d",&w,&a);
            for (int i=0; i<h; i++) {
                bool flag=false;
                for (int j=0; j<u; j++) {
                    if (isin(hx[i],hy[i],ux[j],uy[j],du,w,a)) {
                        flag=true;
                    }
                }
                for (int j=0; j<m; j++) {
                    if (isin(hx[i],hy[i],mx[j],my[j],dm,w,a)) {
                        flag=true;
                    }
                }
                for (int j=0; j<s; j++) {
                    if (isin(hx[i],hy[i],sx[j],sy[j],ds,w,a)) {
                        flag=true;
                    }
                }
                if (flag) ch[i]++;
            }
        }
        int minr=1000;
        for (int i=0; i<h; i++) minr=min(minr,ch[i]);
        if (minr==r) puts("NA");
        else {
            bool first=false;
            for (int i=0; i<h; i++) {
                if (ch[i]==minr) {
                    if (first) {
                        printf(" ");
                    }
                    printf("%d",i+1);
                    first=true;
                }
            }
            puts("");
        }
    }
}
