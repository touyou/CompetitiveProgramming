#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int n, m;
int c[10000];
vector<int> dist[10000];
int prev[10000];
int calc() {
    priority_queue<P> que;
    que.push(P(0,0));
    int r=0, g=0;
    while (!que.empty()) {
        P p=que.top(); que.pop();
        int v=p.second;
        if (dist[v].size()==0) {
            if (r<p.first) {
                r=p.first;
                g=p.second;
            }
            continue;
        }
        for (int i=0; i<dist[v].size(); i++) {
            int to=dist[v][i];
            que.push(P(p.first+c[to],to));
        }
    }
    for (int v=g; v!=0; v=prev[v]) {
        c[v]=0;
    }
    return r;
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        int s, a; scanf("%d%d",&s,&a);
        if (s!=0) {
            dist[s-1].push_back(i);
            prev[i]=s-1;
        }
        c[i]=a;
    }
    int res=c[0];
    c[0]=0;
    for (int i=0; i<m; i++) {
        res+=calc();
    }
    printf("%d\n",res);
}
