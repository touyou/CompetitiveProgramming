#include <cstdio>
#include <set>
#include <vector>
using namespace std;
vector<int> list[10000];
set<int> cnt[10000];
void solve(int x, int b) {
    for (int i=0; i<list[x].size(); i++) {
        if (list[x][i]==b) continue;
        if (cnt[b].find(list[x][i])==cnt[b].end()) {
            cnt[b].insert(list[x][i]);
            solve(list[x][i],b);
        }
    }
}
int main() {
    int n, m; scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        int a, b; scanf("%d%d",&a,&b);
        list[b-1].push_back(a-1);
    }
    for (int i=0; i<n; i++) solve(i, i);
    int res=0;
    for (int i=0; i<n; i++) {
        if (cnt[i].size()==n-1) res++;
    }
    printf("%d\n",res);
}
