#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct hash {
    vector<string> key;
    int find(string str) {
        for (int i=0; i<key.size(); i++) {
            if (key[i]==str) return i;
        }
        key.push_back(str);
        return key.size()-1;
    }
    string fstr(int k) {
        return key[k];
    }
};
int es[333], s;
bool used[333];
vector<string> root;
bool dfs(int x, int cnt, hash *h) {
    root.push_back((*h).fstr(x));
    used[x]=true;
    cnt++;
    if (es[x]==-1&&cnt==s) return true;
    else if (es[x]==-1) return false;
    if (used[es[x]]) return false;
    return dfs(es[x],cnt,h);
}
int main() {
    int t; scanf("%d",&t);
    for (int ix=1; ix<=t; ix++) {
        scanf("%d",&s);
        hash h;
        memset(es, -1, sizeof(es));
        for (int i=0; i<s-1; i++) {
            string s1, s2; cin>>s1>>s2;
            es[h.find(s1)]=h.find(s2);
        }
        for (int i=0; i<s; i++) {
            root.clear();
            memset(used, 0, sizeof(used));
            if (dfs(i,0,&h)) {
                cout<<"Scenario #"<<ix<<":"<<endl;
                for (int j=0; j<root.size(); j++) cout<<root[j]<<endl;
                cout<<endl;
                break;
            }
        }
    }
}