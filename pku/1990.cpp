#include <cstdio>
int bit[20001], n;
int sum(int i) {
    int s=0;
    while (i>0) {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i, int x) {
    while (i<=n) {
        bit[i]+=x;
        i+=i&-i;
    }
}
struct cow { int x, v; };
bool comp(const cow& c1, const cow& c2) {
    return c1.v<c2.v;
}
cow c[20000];
/*
Σmax(v[i],v[j])*|x[i]-x[j]|
*/
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d%d",&c[i].v,&c[i].x);
    sort(c, c+n, comp);
