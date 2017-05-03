#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct inter {
    int s, e, ef;
    bool operator<(const inter& a)const{
        return s<a.s;
    }
};
int n,m,r,s,e,ef;
int dp[1000];
inter list[1000];
int main() {
    memset(dp, 0, sizeof(dp));
    scanf("%d%d%d",&n,&m,&r);
    for (int i=0; i<m; i++) {
        scanf("%d%d%d",&list[i].s,&list[i].e,&list[i].ef);
    }
    sort(list,list+m);
    int res=0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<i; j++) {
            if (list[i].s>=list[j].e+r) dp[i]=max(dp[i],dp[j]);
        }
        dp[i]+=list[i].ef;
        res=max(res,dp[i]);
    }
    printf("%d\n",res);
}
