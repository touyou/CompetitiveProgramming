#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> mark[1000], cap[1000];
int main() {
    int n, m; scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        int x, y; scanf("%d%d",&x,&y);
        mark[y-1].push_back(x);
    }
    for (int i=0; i<m; i++) {
        int a, b; scanf("%d%d",&a,&b);
        cap[b-1].push_back(a);
    }
    int cnt=0, bres=0;
    for (int i=0; i<1000; i++) {
        int ms=mark[i].size(), cs=cap[i].size();
        if (ms==0) continue;
        cnt+=min(ms,cs);
        for (int j=0; j<ms; j++) {
            for (int k=0; k<cs; k++) {
                if (mark[i][j]==cap[i][k]) {
                    cap[i][k]+=1000;
                    bres++;
                    break;
                }
            }
        }
    }
    printf("%d %d\n",cnt,bres);
}
