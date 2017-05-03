#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int h, w, k;
string f[50];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int main() {
    scanf("%d%d%d",&h,&w,&k);
    for (int i=0; i<h; i++) cin>>f[i];
    queue<pair<pair<P, P>, set<P> > > que;
    que.push(make_pair(make_pair(P(0,0),P(0,0)),set<P>()));
    int res=0;
    while (!que.empty()) {
        int x=que.front().first.first.first;
        int y=que.front().first.first.second;
        int lim=que.front().first.second.first;
        int cnt=que.front().first.second.second;
        set<P> s=que.front().second;
        que.pop();
        if (x==h-1&&y==w-1) res=max(res, cnt);
        for (int i=0; i<4; i++) {
            if (lim==k&&i<2) continue;
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<0||nx>=h||ny<0||ny>=w) continue;
            if (f[nx][ny]=='#') continue;
            if (f[nx][ny]=='.'||s.find(P(nx,ny))!=s.end()) {
                if (i>=2) que.push(make_pair(make_pair(P(nx,ny),P(lim,cnt)),s));
                else que.push(make_pair(make_pair(P(nx,ny),P(lim+1,cnt)),s));
            } else {
                set<P> ss=s;
                ss.insert(P(nx,ny));
                int val=f[nx][ny]-'0';
                if (i>=2) que.push(make_pair(make_pair(P(nx,ny),P(lim,cnt+val)),ss));
                else que.push(make_pair(make_pair(P(nx,ny),P(lim+1,cnt+val)),ss));
            }
        }
    }
    printf("%d\n",res);
}
