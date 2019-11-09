#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
#define eps 1e-9
#define inf INT_MAX
struct U {
  double dist, ta, si, co;
  int r, v, vit;
  U(){}
  U(double dist, double ta, double si, double co, int r, int v, int vit) : dist(dist), ta(ta), si(si), co(co), r(r), v(v), vit(vit) {
  }
};
bool comp(const U& a, const U& b) {
  return a.dist<b.dist;
}
int R, n;
U ufo[100];
int main() {
  while (scanf("%d%d",&R,&n)) {
    if (!R&&!n) break;
    for (int i=0; i<n; i++) {
      int x, y, r, v;
      scanf("%d%d%d%d",&x,&y,&r,&v);
      double dist=sqrt((double)x*x+y*y);
      ufo[i]=U(dist, (x==0?inf:(double)y/x), y/dist, x/dist, r, v, 0);
    }
    int res=0, exec=0;
    while (exec<n) {
      for (int i=0; i<n; i++) {
        if (ufo[i].vit) continue;
        // printf("%d\n",ufo[i].v);
        ufo[i].dist-=(double)ufo[i].v;
        if (ufo[i].dist<R+eps) {
          res++; exec++;
          ufo[i].vit=0;
        }
      }
      sort(ufo, ufo+n, comp);
      double getr, gets, getc;
      for (int i=0; i<n; i++) {
        if (ufo[i].vit) continue;
        // puts("ok");
        exec++;
        ufo[i].vit=0;
        getr=ufo[i].ta;
        gets=ufo[i].si;
        getc=ufo[i].co;
        break;
      }
      for (int i=0; i<n; i++) {
        if (ufo[i].vit) continue;
        double x=ufo[i].dist*ufo[i].co, y=ufo[i].dist*ufo[i].si;
        if (x*x+y*y<ufo[i].dist+eps) {
          exec++;
          ufo[i].vit=0;
          continue;
        }
        if (x==0&&(ufo[i].co>-eps)!=(getc>-eps)) continue;
        if (y==0&&(ufo[i].si>-eps)!=(gets>-eps)) continue;
        if ((ufo[i].si>-eps)!=(gets>-eps)&&(ufo[i].co>-eps)!=(getc>-eps)) continue;
        double dis;
        if (getr!=inf) dis=abs(getr*x-y)/sqrt(getr*getr+1);
        else dis=abs(ufo[i].co);
        if (dis<ufo[i].r+eps) {
          exec++;
          ufo[i].vit=0;
        }
      }
    }
    printf("%d\n",res);
  }
}
