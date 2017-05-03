#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
double EPS=1e-10;
double add(double a, double b) {
    if (abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}
struct P {
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator - (P p) {
        return P(add(x,-p.x),add(y,-p.y));
    }
    double dot(P p) {
        return add(x*p.x,y*p.y);
    }
    double det(P p) {
        return add(x*p.y,-y*p.x);
    }
};
bool comp(const P& p, const P& q) {
    if (p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
vector<P> grahamscan(P* ps, int n) {
    sort(ps, ps+n, comp);
    int k=0;
    vector<P> qs(n*2);
    for (int i=0; i<n; i++) {
        while (k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    for (int i=n-2, t=k; i>=0; i--) {
        while (k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
P ps[100];
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) {
            double x, y; scanf("%lf%*c%lf",&x,&y);
            ps[i]=P(x,y);
        }
        vector<P> qs=grahamscan(ps,n);
        printf("%d\n",n-qs.size());
    }
}
