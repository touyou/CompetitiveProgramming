#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> P;
vector<int> g;
vector<P> E;
int n, m;
string s;
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        int a, b; scanf("%d%d",&a,&b);
        E.push_back(P(a-1, b-1));
    }
    cin>>s;
    string num="";
    int target;
    for (int i=0; i<s.length(); i++) {
        if ('0'<=s[i]&&s[i]<='9') num.push_back(s[i]);
    }
    stringstream ss;
    ss<<num; ss>>target; target--;
    for (int i=s.length()-1; i>=5; i--) {
        if (s[i]=='w'&&s[i-1]=='w'&&s[i-2]=='\"') {
            g.push_back(1);
            i-=2;
        } else if (s[i]=='w'&&'0'<=s[i-1]&&s[i-1]<='9') {
            g.push_back(1);
            break;
        } else if (s[i]=='\"') {
            g.push_back(0);
        } else if ('0'<=s[i]&&s[i]<='9') {
            g.push_back(0);
            break;
        }
    }
    reverse(g.begin(), g.end());
    //cout<<target<<endl;
    //for (int i=0; i<g.size(); i++) cout<<g[i]<<endl;
    cout<<bfs(target)<<endl;
}
