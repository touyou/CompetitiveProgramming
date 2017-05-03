#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
double dp[16][3][3];
char s,t,b;
int main() {
    int n, sx, sy, tx, ty, bx, by;
    while (scanf("%d",&n)) {
        if (!n) break;
        memset(dp, 0, sizeof(dp));
        cin>>s>>t>>b;
        sx=(s-'A')/3; sy=(s-'A')%3;
        tx=(t-'A')/3; ty=(t-'A')%3;
        bx=(b-'A')/3; by=(b-'A')%3;
        dp[0][sx][sy]=1.0;
        for (int i=0; i<=n; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    for (int l=0; l<4; l++) {
                        int x=j+dx[l], y=k+dy[l];
                        if (x>=0&&x<3&&y>=0&&y<3&&(x!=bx||y!=by)) {
                            dp[i+1][x][y]+=dp[i][j][k]/4.0;
                        } else {
                            dp[i+1][j][k]+=dp[i][j][k]/4.0;
                        }
                    }
                    // printf("%f%c",dp[i][j][k],k==2?'\n':' ');
                }
            }
        }
        printf("%.8f\n",dp[n][tx][ty]);
    }
}