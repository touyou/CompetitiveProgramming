#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n, m;
    while (scanf("%d%d",&n,&m)) {
        if (n==0&&m==0) break;
        vector<int> friends[n];
        for (int i=0; i<m; i++) {
            int a,b; scanf("%d%d",&a,&b);
            friends[a-1].push_back(b-1);
            friends[b-1].push_back(a-1);
        }
        set<int> s;
        for (int i=0; i<friends[0].size(); i++) {
            s.insert(friends[0][i]);
            for (int j=0; j<friends[friends[0][i]].size(); j++) {
                if (friends[friends[0][i]][j]!=0) s.insert(friends[friends[0][i]][j]);
            }
        }
        printf("%d\n",s.size());
    }
}