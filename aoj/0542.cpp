#include <cstdio>
#include <climits>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
#include <queue>
#define inf INT_MAX/2
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
struct office {
    int minl[100001], w, h, is, js, maps[500][500];
    bool used[500][500];
    office () {}
    office (int w, int h, int is, int js) : w(w), h(h), is(is), js(js) {
        for (int i=0; i<h; i++) for (int j=0; j<w; j++) {
            used[i][j]=false;
        }
    }
    void calc(int r) {
        fill(minl, minl+(r+1), inf);
        if (maps[is][js]==0) return;
        minl[0]=0;
        draw(r);
    }
    bool isin(int x, int y) {
        return x>=0&&x<h&&y>=0&&y<w;
    }
    void draw(int r) {
        priority_queue<PP, vector<PP>, greater<PP> > que;
        que.push(make_pair(1,P(is,js)));
        int l=1, cnt=0;
        used[is][js]=true;
        while (!que.empty()) {
            PP p=que.top(); que.pop();
            l=max(l, p.first);
            int x=p.second.first, y=p.second.second;
            cnt++;
            if (cnt>=r) minl[r]=min(minl[r], l);
            else minl[cnt]=min(minl[cnt], l);
            for (int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if (isin(nx,ny)&&!used[nx][ny]) {
                    que.push(make_pair(maps[nx][ny],P(nx,ny)));
                    used[nx][ny]=true;
                }
            }
       }
    }
};
int main() {
    int r;
    while (scanf("%d",&r)) {
        if (!r) break;
        office o1, o2;
        int w, h, x, y;
        scanf("%d%d%d%d",&w,&h,&x,&y);
        o1=office(w,h,y-1,x-1);
        for (int i=0; i<h; i++) for (int j=0; j<w; j++) {
            scanf("%d",&o1.maps[i][j]);
        }
        scanf("%d%d%d%d",&w,&h,&x,&y);
        o2=office(w,h,y-1,x-1);
        for (int i=0; i<h; i++) for (int j=0; j<w; j++) {
            scanf("%d",&o2.maps[i][j]);
        }
        o1.calc(r); o2.calc(r);
        int res=inf;
        for (int i=r; i>=0; i--) {
            res=min(res, o1.minl[i]+o2.minl[r-i]);
        }
        printf("%d\n",res);
    }
}
