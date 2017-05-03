#include <cstdio>
int map[500][500], sum[2][500];
int n, k;
int main() {
    scanf("%d%d",&n,&k);
    for (int i=0; i<k; i++) {
        int x, y; scanf("%d%d",&x,&y);
        map[x-1][y-1]=1;
        sum[0][x-1]++;
        sum[1][y-1]++;
    }
    
