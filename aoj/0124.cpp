#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n, f=0;
    while (cin>>n) {
        if (!n) break;
        if (f) cout<<endl;
        else f=1;
        vector<int> m;
        map<int, vector<string> > f;
        for (int i=0; i<n; i++) {
            string name; cin>>name;
            int a,b,c; cin>>a>>b>>c;
            int p=-(a*3+c);
            if (count(m.begin(), m.end(), p)==0) m.push_back(p);
            f[p].push_back(name);
        }
        sort(m.begin(),m.end());
        for (int i=0; i<m.size(); i++) {
            for (int j=0; j<f[m[i]].size(); j++) {
                cout<<f[m[i]][j]<<","<<-m[i]<<endl;
            }
        }
    }
}
