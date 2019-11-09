#include <cstdio>
#include <algorithm>
using namespace std;
int mat[100][100];
int n, w, h, s, t;
int cnt(int x1, int y1, int x2, int y2) {
    int res=0;
    for (int i=x1; i<x2; i++)
        for (int j=y1; j<y2; j++) res+=mat[i][j];
    return res;
}
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        scanf("%d%d",&w,&h);
        for (int i=0; i<h; i++) for (int j=0; j<w; j++) mat[i][j]=0;
        for (int i=0; i<n; i++) {
            int x,y; scanf("%d%d",&x,&y);
            mat[y-1][x-1]=1;
        }
        scanf("%d%d",&s,&t);
        int res=0;
        for (int i=0; i<=h-t; i++) {
            for (int j=0; j<=w-s; j++) {
                res=max(res, cnt(i,j,i+t,j+s));
            }
        }
        printf("%d\n",res);
    }
}
