#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct hash {
    vector<string> vec;
    int add(string s) {
        for (int i=0; i<vec.size(); i++) if (vec[i]==s) return i;
        vec.push_back(s);
        return vec.size()-1;
    }
    string find(int num) {
        return vec[num];
    }
};
struct tree {
    vector<int> G[10000];
    set<int> child;
    int used[10000];
    tree() { memset(used,0,sizeof(used)); }
    void solve(int x) {
        if (used[x]==1) return;
        if (G[x].size()==0) {
            child.insert(x);
            return;
        }
        used[x]=1;
        for (int i=0; i<G[x].size(); i++) {
            solve(G[x][i]);
        }
    }
};    
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (n==0) break;
        hash h; tree t;
        for (int i=0; i<n; i++) {
            string s; cin>>s;
            string temp="";
            int root, leaf;
            for (int j=0; j<s.length(); j++) {
                if (s[j]==':') {
                    root=h.add(temp);
                    temp="";
                } else if (s[j]==','||s[j]=='.') {
                    leaf=h.add(temp);
                    t.G[root].push_back(leaf);
                    temp="";
                } else {
                    temp+=s[j];
                }
            }
        }
        t.solve(0);
        // for (int i=0; i<h.vec.size(); i++) {
            // cout<<h.find(i)<<"---"<<<endl;
            // for (int j=0; j<t.G[i].size(); j++) {
                // cout<<h.find(t.G[i][j])<<" ";
            // }
            // cout<<endl;
        // }
        printf("%d\n",t.child.size());
    }
}