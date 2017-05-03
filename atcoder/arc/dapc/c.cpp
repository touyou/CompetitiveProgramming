#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int n,m,K;
int tl[100000];
map<int, map<int, bool> > fl;
int main() {
    scanf("%d%d%d",&n,&m,&K);
    for (int i=0; i<m; i++) {
        string mode; cin>>mode;
        if (mode=="t") {
            int j; scanf("%d",&j); j--;
            map<int, bool>::iterator it=fl[j].begin();
            for (; it!=fl[j].end(); it++) {
                if ((*it).second) {
                    int k=(*it).first;
                    tl[k]++;
                }
            }
            tl[j]++;
        } else if (mode=="f") {
            int j, k; scanf("%d%d",&j,&k); j--; k--;
            fl[j][k]=true;
            fl[k][j]=true;
        } else {
            int j, k; scanf("%d%d",&j,&k); j--; k--;
            fl[j].erase(k);
            fl[k].erase(j);
        }
    }
    sort(tl, tl+n);
    printf("%d\n",tl[n-K]);
}
