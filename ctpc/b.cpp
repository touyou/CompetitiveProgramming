#include <cstdio>
#include <algorithm>
using namespace std;
int board[50][50];
int w,h,k;
bool isin(int x, int y) {
    return x>=0&&x<w&&y>=0&&y<h;
}
// P(x,y) : xが横,yが縦
int main() {
    scanf("%d%d%d",&w,&h,&k);
    for (int i=0; i<k; i++) {
        int x,y,l; scanf("%d%d%d",&x,&y,&l);
        int r=l;
        while (r<=max(w,h)) {
            bool flag=true;
            for (int j=x-r; j<=x+r; j++) {
                if (isin(j,y-r)) {
                    board[y-r][j]++;
                    flag=false;
                }
                if (isin(j,y+r)) {
                    board[y+r][j]++;
                    flag=false;
                }
            }
            for (int j=y-r+1; j<y+r; j++) {
                if (isin(x-r,j)) {
                    board[j][x-r]++;
                    flag=false;
                }
                if (isin(x+r,j)) {
                    board[j][x+r]++;
                    flag=false;
                }
            }
            if (flag) break;
            r+=l+1;
        }
    }
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (board[i][j]%2) putchar('#');
            else putchar('.');
            if (j==w-1) puts("");
        }
    }
}
