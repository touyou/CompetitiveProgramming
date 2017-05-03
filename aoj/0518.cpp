#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> P;
int n;
P st[3000];
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        set<P> stat;
        for (int i=0; i<n; i++) {
            scanf("%d%d",&st[i].first,&st[i].second);
            stat.insert(st[i]);
        }
        int res=0;
        for (int i=0; i<n; i++) {
            P a=st[i];
            for (int j=0; j<n; j++) {
                P b=st[j];
                int dist1=b.first-a.first, dist2=a.second-b.second;
                if (stat.find(P(b.first-dist2,b.second-dist1))!=stat.end()&&stat.find(P(a.first-dist2,a.second-dist1))!=stat.end()) {
                    res=max(res,dist1*dist1+dist2*dist2);
                }
            }
        }
        printf("%d\n",res);
    }
}
