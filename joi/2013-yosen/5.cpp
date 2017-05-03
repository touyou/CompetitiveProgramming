#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct F {
    int x1, y1, d1, x2, y2, d2;
    F() {}
    F(int x1, int y1, int d1, int x2, int y2, int d2) : x1(x1),y1(y1),d1(d1),x2(x2),y2(y2),d2(d2) {}
};
int n, k;
F fish[50];
vector<F> con;
int main() {
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) {
        int x1,y1,d1,x2,y2,d2;
        scanf("%d%d%d%d%d%d",&x1,&y1,&d1,&x2,&y2,&d2);
        fish[i]=F(x1,y1,d1,x2,y2,d2);
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int x1=fish[i].x1, x2=fish[i].x2;
            int y1=fish[i].y1, y2=fish[i].y2;
            int d1=fish[i].d1, d2=fish[i].d2;
            // xy平面
            int cx1=-1, cy1=-1, cx2=-1, cy2=-1;
            if ((x1<fish[j].x1&&fish[j].x1<x2&&y1<fish[j].y1&&fish[j].y1<y2)||
                (x1<fish[j].x1&&fish[j].x1<x2&&y1<fish[j].y2&&fish[j].y2<y2)||
                (x1<fish[j].x2&&fish[j].x2<x2&&y1<fish[j].y1&&fish[j].y1<y2)||
                (x1<fish[j].x2&&fish[j].x2<x2&&y1<fish[j].y2&&fish[j].y2<y2)) {
                cx1=max(x1,fish[j].x1);
                cy1=max(y1,fish[j].y1);
                cx2=min(x2,fish[j].x2);
                cy2=min(y2,fish[j].y2);
            } else continue;
            // yz平面
            int dy1=-1, dd1=-1, dy2=-1, dd2=-1;
            if ((y1<fish[j].y1&&fish[j].y1<y2&&d1<fish[j].d1&&fish[j].d1<d2)||
                (y1<fish[j].y1&&fish[j].y1<y2&&d1<fish[j].d2&&fish[j].d2<d2)||
                (y1<fish[j].y2&&fish[j].y2<y2&&d1<fish[j].d1&&fish[j].d1<d2)||
                (y1<fish[j].y2&&fish[j].y2<y2&&d1<fish[j].d2&&fish[j].d2<d2)) {
                dy1=max(y1,fish[j].y1);
                dd1=max(d1,fish[j].d1);
                dy2=min(y2,fish[j].y2);
                dd2=min(d2,fish[j].d2);
            } else continue;
            // zx平面
            int ex1=-1, ed1=-1, ex2=-1, ed2=-1;
            if ((x1<fish[j].x1&&fish[j].x1<x2&&d1<fish[j].d1&&fish[j].d1<d2)||
                (x1<fish[j].x1&&fish[j].x1<x2&&d1<fish[j].d2&&fish[j].d2<d2)||
                (x1<fish[j].x2&&fish[j].x2<x2&&d1<fish[j].d1&&fish[j].d1<d2)||
                (x1<fish[j].x2&&fish[j].x2<x2&&d1<fish[j].d2&&fish[j].d2<d2)) {
                ex1=max(x1,fish[j].x1);
                ed1=max(d1,fish[j].d1);
                ex2=min(x2,fish[j].x2);
                ed2=min(d2,fish[j].d2);
            } else continue;

            int xx1=max(cx1,ex1), xx2=min(cx2,ex2);
            int yy1=max(cy1,dy1), yy2=min(cy2,dy2);
            int zz1=max(dd1,ed1), zz2=min(dd2,ed2);
            con.push_back(F(xx1,yy1,zz1,xx2,yy2,zz2));
        }
    }

    // 交差している場所列挙
    for (int i=0; i<con.size(); i++) {
