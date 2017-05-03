#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
vector<int> val[10];
int dp[2001];
int main() {
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) {
        int c, g; scanf("%d%d",&c,&g);
        val[g-1].push_back(c);
    }
    for (int i=0; i<10; i++) {
        sort(val[i].rbegin(),val[i].rend());
        for (int j=1; j<val[i].size(); j++) {
            val[i][j]+=val[i][j-1]+j*2;
        }
    }
    for (int i=0; i<10; i++) {
        if (val[i].size()!=0) {
            for (int j=k; j>0; j--) {
                for (int l=1; l<=min(j,(int)val[i].size()); l++) {
                    dp[j]=max(dp[j], dp[j-l]+val[i][l-1]);
                }
            }
        }
    }
    printf("%d\n",dp[k]);
}
