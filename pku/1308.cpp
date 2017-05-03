//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <set>
//using namespace std;
//vector<int> G[300];
//vector<int> to[300];
//set<int> s;
//bool vis[300], ok;
//int st, et, num;
//void dfs(int v) {
//    if (vis[v]) {
//        ok=false;
//        return;
//    }
//    vis[v]=true; num++;
//    for (int i=0; i<G[v].size(); i++) {
//        dfs(G[v][i]);
//    }
//}
//int main() {
//    int cn=1;
//    while (scanf("%d%d",&st,&et)) {
//        if (st==-1&&et==-1) break;
//        for (int i=0; i<300; i++) {
//            G[i].clear();
//            to[i].clear();
//        }
//        num=0; s.clear(); ok=true;
//        memset(vis, 0, sizeof(vis));
//        while (st||et) {
//            G[st].push_back(et);
//            to[et].push_back(st);
//            s.insert(st); s.insert(et);
//            scanf("%d%d",&st,&et);
//        }
//        for (int i=0; i<300; i++) {
//            if (to[i].size()==0&&G[i].size()>0) {
//                dfs(i);
//                break;
//            }
//        }
//        printf("Case %d is ",cn++);
//        if (ok&&num>=s.size()) puts("a tree.");
//        else puts("not a tree.");
//    }
//}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
set<int> s;
int st, et, cnt[10000];
bool istree() {
    set<int>::iterator it;
    int rcnt=0;
    for (it=s.begin(); it!=s.end(); it++) {
        if (cnt[*it]>1) return false;
        if (cnt[*it]==0) rcnt++;
    }
    if (s.size()==0) return true;
    return rcnt==1;
}
int main() {
    int cn=1;
    while (scanf("%d%d",&st,&et)) {
        if (st==-1&&et==-1) break;
        memset(cnt, 0, sizeof(cnt));
        s.clear();
        if (st||et) {
            cnt[et]++;
            s.insert(st); s.insert(et);
            while (scanf("%d%d",&st,&et)) {
                if (!st&&!et) break;
                cnt[et]++;
                s.insert(st); s.insert(et);
            }
        }
        printf("Case %d is ",cn++);
        if (istree()) puts("a tree.");
        else puts("not a tree.");
    }
}
