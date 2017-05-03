#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> P;
static const double PI = 6*asin( 0.5 );
int w, h;
int field[200][200];
int d1[6][2] = {{-1,-1},{-1,0},{0,1},{1,0},{1,-1},{0,-1}};
int d2[6][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{0,-1}};
void solve() {
    scanf("%d%d",&w,&h);
    memset(field, 0, sizeof(field));
    int res=0;
    for (int i=1; i<=h; i++)
        for (int j=1; j<=w; j++) scanf("%d",&field[i][j]);
    /* for (int i=0; i<=h+1; i++) {
        if (i%2) printf(" ");
        for (int j=0; j<=w+1; j++) {
            printf("%d%c",field[i][j],j==w+1?'\n':' ');
        }
    } */
    queue<P> que;
    set<P> done;
    que.push(make_pair(0,0));
    done.insert(make_pair(0,0));
    while (!que.empty()) {
        P now=que.front(); que.pop();
        if (now.first%2==0) {
            for (int i=0; i<6; i++) {
                int x=now.first+d1[i][0], y=now.second+d1[i][1];
                if (x>=0&&x<=h+1&&y>=0&&y<=w+1&&field[x][y]==1) {
                    res++;
                } else if (x>=0&&x<=h+1&&y>=0&&y<=w+1&&field[x][y]==0) {
                    if (done.find(make_pair(x,y))==done.end()) {
                        que.push(make_pair(x,y));
                        done.insert(make_pair(x,y));
                    }
                }
            }
        } else {
            for (int i=0; i<6; i++) {
                int x=now.first+d2[i][0], y=now.second+d2[i][1];
                if (x>=0&&x<=h+1&&y>=0&&y<=w+1&&field[x][y]==1) {
                    res++;
                } else if (x>=0&&x<=h+1&&y>=0&&y<=w+1&&field[x][y]==0) {
                    if (done.find(make_pair(x,y))==done.end()) {
                        que.push(make_pair(x,y));
                        done.insert(make_pair(x,y));
                    }
                }
            }
        }
    }
    printf("%d\n", res);
}
int main() {
    solve();
    return 0;
}
