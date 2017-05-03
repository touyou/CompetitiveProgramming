#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct joi {
int j, o, i;
joi(){j=0;o=0;i=0;}
};
joi sum[1005][1005];
int m,n,k;
int main() {
    scanf("%d%d%d",&m,&n,&k);
    for (int i=1; i<=m; i++) {
        string row; cin>>row;
        for (int j=1; j<=n; j++) {
            sum[i][j].j=sum[i-1][j].j+sum[i][j-1].j-sum[i-1][j-1].j;
            sum[i][j].o=sum[i-1][j].o+sum[i][j-1].o-sum[i-1][j-1].o;
            sum[i][j].i=sum[i-1][j].i+sum[i][j-1].i-sum[i-1][j-1].i;
            if (row[j-1]=='J') sum[i][j].j++;
            if (row[j-1]=='O') sum[i][j].o++;
            if (row[j-1]=='I') sum[i][j].i++;
        }
    }
    int a,b,c,d;
    for (int i=0; i<k; i++) {
        scanf("%d%d%d%d",&a,&b,&c,&d);a--;b--;
        int rj=sum[c][d].j+sum[a][b].j-sum[a][d].j-sum[c][b].j;
        int ro=sum[c][d].o+sum[a][b].o-sum[a][d].o-sum[c][b].o;
        int ri=sum[c][d].i+sum[a][b].i-sum[a][d].i-sum[c][b].i;
        printf("%d %d %d\n",rj,ro,ri);
    }
    /*for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("(%d,%d,%d)%c",sum[i][j].j,sum[i][j].o,sum[i][j].i,j==n-1?'\n':' ');
        }
    }*/
}
