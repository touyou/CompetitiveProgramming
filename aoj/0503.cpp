#include <cstdio>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, in;
ll m;
stack<int> s[3], temp[3];
void input(stack<int>& s) {
    int num; scanf("%d",&num);
    for (int i=0; i<num; i++) {
        int x; scanf("%d",&x);
        s.push(x);
    }
}
void clear(stack<int>& s) {
    while (!s.empty()) s.pop();
}
// 0-a 1-b 2-c
ll dfs(int from, int to) {
    ll res=1;
    bool con=true;
    while (s[0].size()!=n&&s[2].size()!=n&&res<=m) {
        con=true;
        for (int i=0; i<3&&con; i++) {
            for (int j=0; j<3&&con; j++) {
                if (i==to&&j==from) continue;
                if (s[i].empty()) continue;
                if (abs(i-j)!=1) continue;
                if (!s[j].empty()&&s[i].top()<s[j].top()) continue;
                s[j].push(s[i].top()); s[i].pop();
                from=i; to=j;
                con=false;
            }
        }
        res++;
    }
    return res;
}
int main() {
    while (scanf("%d%lld",&n,&m)) {
        if (!n&&!m) break;
        clear(s[0]); clear(s[1]); clear(s[2]);
        input(s[0]); input(s[1]); input(s[2]);
        ll res=m+1;
        if (s[0].size()==n||s[2].size()==n) {
            puts("0");
            continue;
        }
        for (int i=0; i<3; i++) temp[i]=s[i];
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {                               // iからj
                if (s[i].empty()) continue;                         // とりたいところが空
                if (abs(i-j)!=1) continue;                          // 隣接してない
                if (!s[j].empty()&&s[i].top()<s[j].top()) continue; // 置きたいところに置けない
                s[j].push(s[i].top()); s[i].pop();
                res=min(res, dfs(i,j));
                for (int k=0; k<3; k++) s[k]=temp[k];
            }
        }
        printf("%lld\n",res==m+1?-1:res);
    }
    return 0;
}
