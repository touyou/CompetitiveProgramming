#include <cstdio>
#include <iostream>
using namespace std;
int n;
string ne, ol;
bool dfs(int pos, int np, int r) {
    if (np==ne.size()) return true;
    if (r==-1) {
        for (int i=pos+1; i<ol.size(); i++) {
            if (ne[np]==ol[i]) {
                if (dfs(i, np+1, i-pos)) return true;
            }
        }
        return false;
    } else {
        if (pos+r>=ol.size()||ol[pos+r]!=ne[np]) return false;
        else return dfs(pos+r, np+1, r);
    }
}
int main() {
    scanf("%d",&n);
    cin>>ne;
    int res=0;
    for (int i=0; i<n; i++) {
        cin>>ol;
        int flag=0;
        for (int j=0; j<ol.size(); j++) {
            if (ne[0]==ol[j]) if (dfs(j,1,-1)) {
                flag=1;
                break;
            }
        }
        if (flag) res++;
    }
    printf("%d\n",res);
}
