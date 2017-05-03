#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int n, col[10000];
int calc(int x, int c) {
    if (col[x]==c) return n;
    int p=x-1, q=x+1;
    int cnt=1;
    for (;p>=0;p--) {
        if (col[p]==c) cnt++;
        else break;
    }
    for (;q<n; q++) {
        if (col[q]==c) cnt++;
        else break;
    }
    if (cnt<4) return n;
    else if (p<0||q>=n) return n-cnt;
    else if (col[p]!=col[q]) return n-cnt;

    int res=n-cnt;
    while (true) {
        cnt=0;
        c=col[p];
        for (;p>=0;p--) {
            if (col[p]==c) cnt++;
            else break;
        }
        for (;q<n; q++) {
            if (col[q]==c) cnt++;
            else break;
        }
        if (cnt<4) return res;
        else if (p<0||q>=n) return res-cnt;
        else if (col[p]!=col[q]) return res-cnt;
        res-=cnt;
    }
    return res;
}
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        for (int i=0; i<n; i++) {
            scanf("%d",&col[i]);
        }
        int res=INT_MAX/2;
        for (int i=0; i<n; i++) {
            for (int j=1; j<=3; j++) {
                res=min(res,calc(i,j));
            }
        }
        printf("%d\n",res);
    }
}
