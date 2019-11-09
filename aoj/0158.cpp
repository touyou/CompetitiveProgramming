#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> P;
int n;
int dp[1000001];
queue<P> que;
int main() {
    memset(dp, 0, sizeof(dp));
    que.push(P(2,1));
    while (!que.empty()) {
        P p=que.front(); que.pop();
        if (dp[p.first]) continue;
        dp[p.first]=p.second;
        if (p.first!=4&&(p.first-1)%3==0&&((p.first-1)/3)%2) {
            que.push(P((p.first-1)/3,p.second+1));
        }
        if (p.first*2<1000001) {
            que.push(P(p.first*2,p.second+1));
        }
    }
    // for (int i=1; i<=10; i++) printf("%d%c",dp[i],i==10?'\n':' ');
    while (scanf("%d",&n)) {
        if (!n) break;
        printf("%d\n",dp[n]);
    }
}
