#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, pair<int,string> > PP;
string a, b, c;
int k;
int br[1000];
int main() {
    cin>>a>>b;
    scanf("%d",&k);
    c="";
    int n=a.length();
    for (int i=0; i<n; i++) c+='0';
    while (b.length()<n) b="0"+b;
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    queue<PP> que;
    que.push(make_pair(P(0,k),make_pair(0,"")));
    while (!que.empty()) {
        PP p=que.front(); que.pop();
        int i=p.first.first;
        int x=p.first.second;
        int br=p.second.first;
        string s=p.second.second;
        if (s.length()==n) {
            if (c<s) c=s;
            continue;
        }
        if (a[i]-br>=b[i]) {
            string temp="";
            temp+=a[i]-br-b[i]+'0';
            que.push(make_pair(P(i+1,x),make_pair(0,(temp+s))));
        } else {
            string temp="";
            temp+=a[i]-br+10-b[i]+'0';
            if (x>0) que.push(make_pair(P(i+1,x-1),make_pair(0,(temp+s))));
            que.push(make_pair(P(i+1,x),make_pair(1,(temp+s))));
        }
    }
    bool flag=false;
    for (int i=0; i<c.length(); i++) {
        if (c[i]!='0') {
            flag=true;
            putchar(c[i]);
        } else if (flag) {
            putchar(c[i]);
        }
    }
    puts("");
}
