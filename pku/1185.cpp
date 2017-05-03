#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n, m; cin>>n>>m;
    string map[n];
    int d[8][2]={{-2,0},{-1,0},{0,-2},{0,-1},{1,0},{2,0},{0,1},{0,2}};
    for (int i=0; i<n; i++) cin>>map[i];
    int res=0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if (map[i][j]=='P') {
            bool flag=true;
            for (int k=0; k<8; k++) {
                int x=i+d[k][0], y=j+d[k][1];
                if (x>=0&&x<n&&y>=0&&y<m&&map[x][y]=='X') {
                        flag=false;
                        break;
                }
            }
            if (flag) {
                map[i][j]='X';
                res++;
            }
        }
    }
    printf("%d\n",res);
}
