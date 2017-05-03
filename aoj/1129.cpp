#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
int main() {
    int n, r;
    while (scanf("%d%d",&n,&r)) {
        if (!n&&!r) break;
        deque<int> deq;
        for (int i=n; i>=1; i--) deq.push_back(i);
        for (int i=0; i<r; i++) {
            int p, c; scanf("%d%d",&p,&c);
            stack<int> ue, shita;
            for (int j=0; j<p-1; j++) {
                ue.push(deq[0]);
                deq.pop_front();
            }
            for (int j=0; j<c; j++) {
                shita.push(deq[0]);
                deq.pop_front();
            }
            while (!ue.empty()) {
                deq.push_front(ue.top());
                ue.pop();
            }
            while (!shita.empty()) {
                deq.push_front(shita.top());
                shita.pop();
            }
//            for (int i=0; i<n; i++) printf("%d%c",deq[i],i==n-1?'\n':' ');
//            puts("");
        }
        printf("%d\n",deq[0]);
    }
}
