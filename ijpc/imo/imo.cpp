#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
vector<int> edge[100000];
vector<int> load[100000], st;
bool used[100000];
int g[100000], f;
struct BIT {
    int bit[100001], n;
    BIT(int N) {
        n=N;
        memset(bit,0,sizeof(bit));
    }
    int sum(int i) {
        int s=0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};
void dfs(int k, int gn) {
    used[k]=true;
    load[gn].push_back(k);
    int cnt=0;
    for (int i=0; i<edge[k].size(); i++) {
        if (used[edge[k][i]]) continue;
        g[edge[k][i]]=gn;
        dfs(edge[k][i], gn);
        cnt++;
    }
    if (cnt>1) f=1;
    return;
}
long long best_swap(int N, int M,int E[][2])
{
	if (N==1) return 0;
    set<P> s;
    memset(g, -1, sizeof(g));
    for (int i=0; i<M; i++) {
        if (E[i][0]>E[i][1]) swap(E[i][0],E[i][1]);
        if (s.find(P(E[i][0],E[i][1]))!=s.end()) continue;
        edge[E[i][0]].push_back(E[i][1]);
        edge[E[i][1]].push_back(E[i][0]);
        s.insert(P(E[i][0],E[i][1]));
    }
    int gn=0;
    f=0;
    for (int i=0; i<N&&f==0; i++) {
        if (g[i]==-1&&edge[i].size()<2) {
            g[i]=gn;
            dfs(i,gn);
            gn++;
        }
    }
    for (int i=0; i<N&&f==0; i++) if (g[i]==-1) f=1;
    if (f==1) return -1;
    ll ans=0;
    for (int i=0; i<gn; i++) {
        int x=load[i].size();
        if (x<=2) continue;
        if (edge[load[i][x-1]].size()>1) return -1;
        BIT bit(N);
        ll res1=0, res2=0;
        for (int j=0; j<x; j++) {
            int ret=bit.sum(load[i][j]+1);
            res1 += j - ret;
            res2 += ret;
            bit.add(load[i][j]+1,1);
        }
        ans+=min(res1,res2);
    }
    return ans;
}
