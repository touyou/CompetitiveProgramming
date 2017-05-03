#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <map>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;
const int INF=INT_MIN/2;
int dp[5000], dp2[5000][5000];
vector<P> dcnt[5000];
int a[5000];
int main() {
    int n;
    scanf("%d", &n);
    fill(dp,dp+n,INF);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) {
        int l=-1, r=n-1;
        while (r-l>1) {
            int mid=(l+r)/2;
            if (dp[mid]<=a[i]) {
                r=mid;
            } else {
                l=mid;
            }
        }
        if (dp[r]!=a[i]) {
            dp[r]=a[i];
            dcnt[r].push_back(P(a[i],i));
        }
    }
    int res=0;
    while (dp[res]!=INF&&res<n) {
        res++;
    }
    for (int i=0; i<dcnt[0].size(); i++) {
        dp2[0][i]=1;
    }
    for (int i=1; i<res; i++) {
        for (int j=0; j<dcnt[i].size(); j++) {
            for (int k=0; k<dcnt[i-1].size(); k++) {
                if (dcnt[i-1][k].fi>dcnt[i][j].fi&&dcnt[i-1][k].se<dcnt[i][j].se) 
                    dp2[i][j]+=dp2[i-1][k];
            }
        }
    }
/*    for (int i=0; i<res; i++) for (int j=0; j<dcnt[i].size(); j++) {
        printf("%d %d%c",dcnt[i][j].fi,dcnt[i][j].se,j==dcnt[i].size()-1?'\n':':');
    }*/
    int rcnt=0;
    for (int i=0; i<dcnt[res-1].size(); i++) {
        rcnt+=dp2[res-1][i];
    }
    printf("%d %d\n",res, rcnt);
}
