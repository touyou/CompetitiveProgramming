#include <cstdio>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> P;
int n, m;
set<P> ans;
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<=1000; i++) {
        for (int j=0; j<=1000; j++) {
            if (i*i+j==n&&i+j*j==m) ans.insert(P(i,j));
        }
    }
    printf("%d\n",ans.size());
}