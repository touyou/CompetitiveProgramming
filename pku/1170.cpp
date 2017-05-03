#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
map<int, int> cton;
struct item {
    int n, p;
    int use[5];
};
P bask[5];
item spec[100];
int b, s;
int dfs(int now, int cost) {
    if (now==s) return cost;
    int res=cost;
    for (int k=0;;k++) {
        bool flag=true;
        for (int i=0; i<5; i++) {
            bask[i].first-=spec[now].use[i]*k;
            if (bask[i].first<0) flag=false;
        }
        if (flag) {
            int diff=0;
            for (int i=0; i<5; i++) {
                diff+=spec[now].use[i]*k*bask[i].second;
            }
            diff-=spec[now].p*k;
            res=min(res,dfs(now+1,cost-diff));
        }
        for (int i=0; i<5; i++) {
            bask[i].first+=spec[now].use[i]*k;
        }
        if (!flag) break;
    }
    return res;
}
int main() {
    int sum=0;
    scanf("%d",&b);
    for (int i=0; i<b; i++) {
        int c, k, p; scanf("%d%d%d",&c,&k,&p);
        cton[c]=i;
        bask[i]=P(k,p);     // first=個数 second=Price
        sum+=k*p;
    }
    scanf("%d",&s);
    for (int i=0; i<s; i++) {
        int n; scanf("%d",&n);
        for (int j=0; j<n; j++) {
            int c, k; scanf("%d%d",&c,&k);
            spec[i].use[cton[c]]=k;
        }
        int p; scanf("%d",&p);
        spec[i].n=n; spec[i].p=p;
    }
    printf("%d\n",dfs(0,sum));
}
