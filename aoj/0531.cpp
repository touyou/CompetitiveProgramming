#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int w, h, n;
int x1[1000],x2[1000],y1[1000],y2[1000];
bool mp[3000][3000];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main() {
    while (scanf("%d%d",&w,&h)) {
        if (!w&&!h) break;
        scanf("%d",&n);
        vector<int> x, y;
        for (int i=0; i<n; i++) {
            scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
            x.push_back(x1[i]); x.push_back(x2[i]);
            y.push_back(y1[i]); y.push_back(y2[i]);
        }
        x.push_back(0); x.push_back(w);
        y.push_back(0); y.push_back(h);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        x.erase(unique(x.begin(),x.end()), x.end());
        y.erase(unique(y.begin(),y.end()), y.end());
        int X=x.size(), Y=y.size();
        for (int i=0; i<n; i++) {
            x1[i]=lower_bound(x.begin(),x.end(),x1[i])-x.begin();
            x2[i]=lower_bound(x.begin(),x.end(),x2[i])-x.begin();
            y1[i]=lower_bound(y.begin(),y.end(),y1[i])-y.begin();
            y2[i]=lower_bound(y.begin(),y.end(),y2[i])-y.begin();
        }
        for (int i=0; i<Y; i++) for (int j=0; j<X; j++) mp[i][j]=i==Y-1||j==X-1;
        for (int i=0; i<n; i++) {
            for (int j=x1[i]; j<x2[i]; j++) {
                for (int k=y1[i]; k<y2[i]; k++) mp[k][j]=1;
            }
        }
        // for (int i=0; i<Y; i++) for (int j=0; j<X; j++) printf("%d%c",mp[i][j]?1:0,j==X-1?'\n':' ');
        int ans=0;
        for (int i=0; i<Y; i++) {
            for (int j=0; j<X; j++) {
                if (mp[i][j]) continue;
                ans++;
                mp[i][j]=1;
                queue<P> que;
                que.push(P(i,j));
                while (!que.empty()) {
                    int a=que.front().first, b=que.front().second; que.pop();
                    // printf("%d %d\n",a,b);
                    for (int k=0; k<4; k++) {
                        int nx=b+dx[k], ny=a+dy[k];
                        if (nx<0||nx>=X-1||ny<0||ny>=Y-1||mp[ny][nx]) continue;
                        mp[ny][nx]=1;
                        que.push(P(ny,nx));
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}