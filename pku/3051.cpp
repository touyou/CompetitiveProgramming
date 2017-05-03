#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[4][2] = {{1,0}, {0,1},{-1,0},{0,-1}};
int W, H;
vector<string> maps;
int solve(int x, int y) {
    maps[x][y]='.';
    int res = 1;
    for (int i=0; i<4; i++) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if (nx>=0&&nx<maps.size()&&ny>=0&&ny<maps[0].length()&&maps[nx][ny]=='*') {
            res += solve(nx, ny);
        }
    }
    return res;
}
int main() {
    scanf("%d%d",&W,&H);
    for (int i=0; i<H; i++) {
        string in; cin >> in;
        maps.push_back(in);
    }
    int res = 0;
    for (int i=0; i<H; i++) for (int j=0; j<W; j++) {
        if (maps[i][j]=='*') {
            res = max(res, solve(i, j));
        }
    }
    printf("%d\n", res);
}
