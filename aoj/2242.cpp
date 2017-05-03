// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2242
// 高々1000個のEranameかつデータベースにかぶりがないことから最初の年とデータとしてのこっている最後の年をEranameをKeyにもっておき愚直に探索する
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int n, q, year1, year2, query;
string name;
int main() {
    while (scanf("%d%d",&n,&q)) {
        if (n==0&&q==0) break;
        map<string, P> era;
        vector<string> names;
        for (int i=0; i<n; i++) {
            cin >> name >> year1 >> year2;
            era[name] = P(year2-year1+1, year2);
            names.push_back(name);
        }
        for (int i=0; i<q; i++) {
            scanf("%d",&query);
            for (int j=0; j<names.size(); j++) {
                P p = era[names[j]];
                if (p.first <= query && p.second >= query) {
                    cout << names[j] << " " << query-p.first+1 << endl;
                    break;
                } else if (j == names.size()-1) {
                    puts("Unknown");
                }
            }
        }
    }
}
