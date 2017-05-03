#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int main() {
    map<int, int> mp;
    map<P, int> mpp;
    for (int i=0; i<6; i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        if (mp.find(a)!=mp.end()) mp[a]++;
        else mp[a]=1;
        if (mp.find(b)!=mp.end()) mp[b]++;
        else mp[b]=1;
        if (a>b) swap(a,b);
        if (mpp.find(P(a,b))!=mpp.end()) mpp[P(a,b)]++;
        else mpp[P(a,b)]++;
    }
    map<int, int>::iterator itm;
    map<P, int>::iterator itmp;
    bool flag=true;
    for (itm=mp.begin(); itm!=mp.end(); itm++) {
        if ((*itm).second%4!=0) flag=false;
    }
    for (itmp=mpp.begin(); itmp!=mpp.end(); itmp++) {
        if ((*itmp).second%2!=0) flag=false;
    }
    if (flag) puts("POSSIBLE");
    else puts("IMPOSSIBLE");
}