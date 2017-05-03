#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
using namespace std;
typedef pair<int, int> P;
string emp;
int t, h, x;
int val[6][8], hav[6];
deque<P> deq[6], res[6];
void solve(int nt, int m, int M) {
    if (nt==t) {
        for (int i=0; i<h; i++) {
            m=min(hav[i], m);
            M=max(hav[i], M);
        }
        if (x>M-m) {
            for (int i=0; i<h; i++) {
                res[i].clear();
                for (int j=0; j<deq[i].size(); j++) res[i].push_back(deq[i][j]);
            }
            x=M-m;
        }
    }
    for (int i=0; i<h; i++) {
        deq[i].push_back(P(nt+1,val[i][nt]));
        hav[i]+=val[i][nt];
        solve(nt+1, min(m,hav[i]), max(M, hav[i]));
        hav[i]-=val[i][nt];
        deq[i].pop_back();
    }
}
int main() {
    while (cin>>emp&&emp=="START") {
        scanf("%d%d", &t, &h);
        for (int i=0; i<h; i++) for (int j=0; j<t; j++) {
            scanf("%d",&val[i][j]);
        }
        cin>>emp;
        memset(hav, 0, sizeof(hav));
        x=100000;
        solve(0,100000,-1);
        for (int i=0; i<h; i++) {
            for (int j=0; j<(int)res[i].size(); j++) printf("%d ",res[i][j].first);
            printf("%d\n",hav[i]);
        }
        puts("");
    }
}
