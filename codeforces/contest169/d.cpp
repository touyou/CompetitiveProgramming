#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct lem {
    int m, v, pos;
    lem () {}
    lem (int m, int v, int pos) : m(m), v(v), pos(pos) {}
};
bool comp(const lem& a, const lem& b) {
    if (a.m!=b.m) return a.m<b.m
    return a.v<b.v;
}
lem lems[100000];
vector<int> ans;
int main() {
    int n, k, h;
    scanf("%d%d%d",&n,&k,&h);
    for (int i=0; i<n; i++) scanf("%d",&lem[i].m);
    for (int i=0; i<n; i++) scanf("%d",&lem[i].v);
    for (int i=0; i<n; i++) lem[i].pos=i+1;
    sort(lem, lem+n, comp);
    
}
