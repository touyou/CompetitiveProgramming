#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
struct P {
    int ow, oh, id;
    int scale;
    P () {}
    P (int ow, int oh, int id) : ow(ow), oh(oh), id(id) {
        scale=ow*oh;
    }
};
struct P2 {
    double x1, x2, y1, y2;
    P2() {}
    P2(double x1,double y1,double x2,double y2):x1(x1),y1(y1),x2(x2),y2(y2){}
};
bool comp(const P& a, const P& b) {
    if (a.ow==b.ow||a.oh==b.oh) return a.scale<b.scale;
    return a.ow<b.ow&&a.oh<b.oh;
    
}
int w, h, n;
P in[100];
P2 res[100];
int bigw, bigh;
//bool used[100][100];
int main() {
    scanf("%d%d%d",&w,&h,&n);
    for (int i=0; i<n; i++) {
        int ow, oh; scanf("%d%d",&ow,&oh);
        in[i]=P(ow,oh,i);
    }
    sort(in, in+n, comp);
    bigw=bigh=0;
    for (int i=0; i<n; i++) {
        int id=in[i].id;
        if (bigw+in[i].ow>w&&bigh+in[i].oh>h) {
            res[id]=P2(-1.0,-1.0,-1.0,-1.0);
        } else if (bigw+in[i].ow>w) {
            res[id]=P2(0.0,(double)bigh,(double)in[i].ow,(double)bigh+in[i].oh);
            bigh+=in[i].oh;
            bigw=max(bigw,in[i].ow);
        } else if (bigh+in[i].oh>h) {
            res[id]=P2((double)bigw,0.0,(double)bigw+in[i].ow,(double)in[i].oh);
            bigw+=in[i].ow;
            bigh=max(bigh,in[i].oh);
        } else {
            int d1=abs(bigw-in[i].ow);
            int d2=abs(bigh-in[i].oh);
            if (d1<d2) {
                res[id]=P2(0.0,(double)bigh,(double)in[i].ow,(double)bigh+in[i].oh);
                bigh+=in[i].oh;
                bigw=max(bigw,in[i].ow);
            } else {
                res[id]=P2((double)bigw,0.0,(double)bigw+in[i].ow,(double)in[i].oh);
                bigw+=in[i].ow;
                bigh=max(bigh,in[i].oh);
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (res[i].x1==-1) {
            puts("-1 -1 -1 -1");
        } else {
            P2 p=res[i];
            printf("%.1f %.1f %.1f %.1f\n",p.x1,p.y1,p.x2,p.y2);
        }
    }
}
