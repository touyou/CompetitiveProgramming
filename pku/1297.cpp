#include <cstdio>
#include <cfloat>
#include <algorithm>
#include <vector>
using namespace std;
struct comb {
    int num;
    double cost;
};
int main() {
    int m, n;
    while (scanf("%d%d",&m,&n)) {
        if (!(m&&n)) break;
        int list[m];
        vector<comb> dp[m];
        comb sale[n];
        for (int i=0; i<m; i++) scanf("%d",&list[i]);
        for (int i=0; i<n; i++) scanf("%d%lf",&sale[i].num,&sale[i].cost);
        for (int i=n-1; i>=0; i--) {
            if (sale[i].num==list[m-1]) {
                comb temp;
                temp.num=i; temp.cost=sale[i].cost;
                dp[m-1].push_back(temp);
            }
        }
        for (int i=m-2; i>=0; i--) {
            for (int j=0; j<dp[i+1].size(); j++) {
                if (dp[i+1][j].cost!=DBL_MAX) {
                    for (int k=dp[i+1][j].num-1; k>=0; k--) {
                        if (sale[k].num==list[i]) {
                            comb temp;
                            temp.num=k;
                            temp.cost=dp[i+1][j].cost+sale[k].cost;
                            dp[i].push_back(temp);
                        }
                    }
                }
            }
        }
        if (dp[0].size()!=0) {
            double res = DBL_MAX;
            for (int i=0; i<dp[0].size(); i++) {
                res = min(res, dp[0][i].cost);
            }
            printf("%.2lf\n",res);
        } else {
            printf("Impossible\n");
        }
    }
}
