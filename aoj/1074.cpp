#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int, string> P;
bool comp(const P& a, const P& b) {
    if (a.first!=b.first) return a.first<b.first;
    return a.second<b.second;
}
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        vector<string> cnt[31];
        map<string, int> mp;
        P po[n];
        for (int i=0; i<n; i++) {
            string name; cin>>name;
            po[i]=P(0,name);
            mp[name]=i;
            int m; scanf("%d",&m);
            for (int j=0; j<m; j++) {
                int d; scanf("%d",&d);
                cnt[d].push_back(name);
            }
        }
        for (int i=0; i<31; i++) {
            int sz=cnt[i].size();
            int x=n-sz+1;
            for (int j=0; j<sz; j++) {
                po[mp[cnt[i][j]]].first+=x;
            }
        }
        sort(po, po+n, comp);
        cout<<po[0].first<<" "<<po[0].second<<endl;
    }
}