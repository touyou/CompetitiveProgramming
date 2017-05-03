#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, pair<int, int> > > P;
int t;
string s, e;
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int main() {
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        cin>>s>>e;
        int sx=7-(s[0]-'a'), sy=s[1]-'1';
        int ex=7-(e[0]-'a'), ey=e[1]-'1';
        if (sx<ex) swap(sx,ex);
        if (sy<ey) swap(sy,ey);
        if (sx==ex&&sy==ey) printf("0 0 0 0\n");
        else {
            printf("%d ",max(sx-ex,sy-ey));
            if (sx==ex||sy==ey||sx+sy==ex+ey||sx-ex==sy-ey) printf("1 ");
            else printf("2 ");
            if (sx==ex||sy==ey) printf("1 ");
            else printf("2 ");
            if (sx+sy==ex+ey||sx-ex==sy-ey) printf("1\n");
            else if ((sx+sy-ex-ey)&1) printf("Inf\n");
            else printf("2\n");
        }
    }
}
