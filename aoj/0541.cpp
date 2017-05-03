#include <cstdio>
#include <cmath>
int field[1000][1000];
int dp[1000][1000];
int h, w, n;
// 0---南 1---東
int main() {
    while (scanf("%d%d%d",&h,&w,&n)) {
        if (!h&&!w&&!n) break;
        for (int i=0; i<h; i++) for (int j=0; j<w; j++)
            scanf("%d",&field[i][j]);
        dp[0][0]=n;
        for (int i=1; i<w; i++) {
            if (field[0][i-1]&&dp[0][i-1]%2) {
                dp[0][i]=floor(dp[0][i-1]/2)+1;
            } else {
                dp[0][i]=floor(dp[0][i-1]/2);
            }
        }
        for (int i=1; i<h; i++) for (int j=0; j<w; j++) {
            dp[i][j]=0;
            if (!field[i-1][j]&&dp[i-1][j]%2) {
                dp[i][j]+=floor(dp[i-1][j]/2)+1;
            } else {
                dp[i][j]+=floor(dp[i-1][j]/2);
            }
            if (j&&field[i][j-1]&&dp[i][j-1]%2) {
                dp[i][j]+=floor(dp[i][j-1]/2)+1;
            } else {
                dp[i][j]+=floor(dp[i][j-1]/2);
            }
        }
        for (int i=0; i<h; i++) for (int j=0; j<w; j++) {
            if (dp[i][j]%2==0) {
                field[i][j]^=1;
            }
            // printf("%d%c",dp[i][j],j==w-1?'\n':' ');
        }
        int nx=0, ny=0;
        while (nx<h&&ny<w) {
            if (field[nx][ny]) ny++;
            else nx++;
        }
        printf("%d %d\n",nx+1,ny+1);
    }
}
