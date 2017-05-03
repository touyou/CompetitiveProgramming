#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> P;
typedef pair<double, pair<int, P> > bfp;
int n, hx, hy, dx, dy;
P c[1001];
double len[1001];
int main() {
    while (scanf("%d%d%d%d%d",&n,&hx,&hy,&dx,&dy)) {
        if (!n&&!hx&&!hy&&!dx&&!dy) break;
        for (int i=0; i<n; i++) {
            scanf("%d%d",&c[i].x,&c[i].y);
            double x=c[i].x-dx, y=c[i].y-dy;
            len[i]=sqrt(x*x+y*y);
        }
        queue<bfp> que;
        que.push(bfp(0.0, make_pair(0,P(hx,hy))));
        bool res=false;
        while (!que.empty()) {
            bfp b=que.front(); que.pop();
            double t=b.first;
            int stat=b.second.first;
            P np=b.second.second;
            bool flag=true;
            for (int i=0; i<n; i++) {
                if (!(stat>>i&1)) {
                    flag=false;
                    double x=c[i].x-np.x, y=c[i].y-np.y;
                    double nt=t+sqrt(x*x+y*y);
                    int nst=stat|1<<i;
                    bool isq=true;
                    for (int j=0; j<n; j++) {
                        if ((nst>>j&1)&&len[j]<=nt) {
                            isq=false;
                            break;
                        }
                    }
                    if (isq) que.push(bfp(nt,make_pair(nst,P(c[i].x,c[i].y))));
                }
            }
            if (flag) {
                res=true;
            }
        }
        if (res) puts("YES");
        else puts("NO");
    }
}