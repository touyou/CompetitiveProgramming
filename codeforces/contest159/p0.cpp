#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<string, string> P;
vector<string> name;
set<P> res;
int hash(string s) {
    int sz=name.size();
    for (int i=0; i<sz; i++) if (name[i]==s) return i;
    name.push_back(s);
    return sz;
}
string tos(int h) {
    return name[h];
}
vector<int> ts[2000][2000];   // ts[i][j]:=hash値iからhash値jへのコンタクトの時間
int main() {
    int n, d, t; scanf("%d%d",&n,&d);
    string a, b;
    for (int i=0; i<n; i++) {
        cin>>a>>b>>t;
        int ah=hash(a), bh=hash(b);
        ts[ah][bh].push_back(t);
    }
    int sz=name.size();
    for (int i=0; i<sz; i++) {
        for (int j=i+1; j<sz; j++) {
            int s1=ts[i][j].size(), s2=ts[j][i].size();
            if (s1==0||s2==0) continue;
            for (int k=0; k<s1; k++) {
                bool flag=false;
                for (int l=0; l<s2; l++) {
                    int dist=abs(ts[i][j][k]-ts[j][i][l]);
                    if (dist>0&&dist<=d) {
                        res.insert(P(tos(i),tos(j)));
                        flag=true;
                        break;
                    }
                }
                if (flag) break;
            }
        }
    }
    printf("%d\n",res.size());
    for (set<P>::iterator i=res.begin(); i!=res.end(); i++) {
        cout << (*i).first << " " << (*i).second << endl;
    }
}
