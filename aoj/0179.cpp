#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<string, int> P;
int main() {
    string w;
    while (cin>>w) {
        if (w=="0") break;
        queue<P> que;
        que.push(P(w,0));
        int res=-1;
        set<string> done;
        while (!que.empty()) {
            P p=que.front(); que.pop();
            char f=p.first[0]; bool flag=true;
            for (int i=1; i<p.first.length(); i++) if (p.first[i]!=f) {
                flag=false;
                break;
            }
            if (flag) {
                res=p.second;
                break;
            }
            for (int i=0; i<p.first.length()-1; i++) {
                if (p.first[i]!=p.first[i+1]) {
                    string temp=p.first;
                    if (temp[i]!='r'&&temp[i+1]!='r') {
                        temp[i]='r'; temp[i+1]='r';
                    } else if (temp[i]!='g'&&temp[i+1]!='g') {
                        temp[i]='g'; temp[i+1]='g';
                    } else if (temp[i]!='b'&&temp[i+1]!='b') {
                        temp[i]='b'; temp[i+1]='b';
                    }
                    if (done.count(temp)==0) {
                        que.push(P(temp,p.second+1));
                        done.insert(temp);
                    }
                }
            }
        }
        if (res==-1) puts("NA");
        else printf("%d\n",res);
    }
}
