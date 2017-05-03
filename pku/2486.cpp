#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct edge
{
    int s, e;
};

int dfs(int K, vector<int> cost, vector<int> dp, vector<edge> map, int npos) 
{
    if (K == 0) return dp[npos-1];
    int res = 0;
    for (int i=0; i<map.size(); i++) {
        if (map[i].s == npos) {
            vector<int> tmp = dp;
            tmp[map[i].e-1] = dp[npos-1] + cost[map[i].e-1];
            res = max(res, dfs(K-1, cost, tmp, map, map[i].e));
        }
        else if (map[i].e == npos) {
            vector<int> tmp = dp;
            tmp[map[i].s-1] = dp[npos-1] + cost[map[i].s-1];
            res = max(res, dfs(K-1, cost, tmp, map, map[i].s));
        }
        
    }
    return res;
}


int main() 
{
    int N, K;
    while (scanf("%d%d", &N, &K) != EOF) {
        vector<edge> map(N-1);
        vector<int> cost(N);
        for (int i=0; i<N; i++) scanf("%d", &cost[i]);
        for (int i=0; i<N-1; i++) scanf("%d%d", &map[i].s, &map[i].e);
        vector<int> dp(N, 0);
        dp[0] = cost[0];
        int res = dfs(K, cost, dp, map, 1);
        printf("%d\n", res);
    }
}

