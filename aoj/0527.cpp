#include <cstdio>
#include <map>
#include <stack>
#define f first
#define s second
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
// 0=white, 1=black
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (!n) break;
        stack<pp> list;
        int in; scanf("%d", &in);
        list.push(make_pair(in, make_pair(0, 1)));
        for (int i=1; i<n; i++) {
            scanf("%d",&in);
            if (i%2!=0) {
                pp bef=list.top(); list.pop();
                // printf("%d %d %d\n", bef.f, bef.s.f, bef.s.s);
                if (bef.f==in) {
                    bef.s.s++;
                    list.push(bef);
                } else {
                    if (list.empty()) {
                        bef.f=in;
                        bef.s.s++;
                        list.push(bef);
                    } else {
                        pp bef2=list.top(); list.pop();
                        bef2.s.s=bef.s.s+1;
                        list.push(bef2);
                    }
                }
            } else {
                pp bef=list.top();
                // printf("%d %d %d\n", bef.f, bef.s.f, bef.s.s);
                if (bef.f==in) {
                    list.pop();
                    bef.s.s++;
                    list.push(bef);
                } else {
                    list.push(make_pair(in, make_pair(i, i+1)));
                }
            }
        }
        int res=0;
        while (!list.empty()) {
            pp x=list.top(); list.pop();
            // printf("%d %d %d\n",x.f,x.s.f,x.s.s);
            if (!x.f) res+=x.s.s-x.s.f;
        }
        printf("%d\n",res);
    }
}
