#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int n, q, c[300000];
P qs[100000], ans[100000];
int main() {
    scanf("%d%d",&n,&q);
    for (int i=0; i<n; i++) scanf("%d",&c[i]);
    for (int i=0; i<q; i++) {
        int in; scanf("%d",&in);
        qs[i] = P(in, i);
    }
    sort(qs, qs+q);
    sort(cs, cs+n);
    for (int i=0; i<q; i++) {

