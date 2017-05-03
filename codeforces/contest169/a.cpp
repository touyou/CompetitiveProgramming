#include <cstdio>
#include <algorithm>
using namespace std;
int n, a, b;
int h[2000];
int main() {
    scanf("%d%d%d",&n,&a,&b);
    for (int i=0; i<n; i++) scanf("%d",&h[i]);
    sort(h, h+n);
    int x1=h[b-1];
    int x2=h[b];
    printf("%d\n",x2-x1);
}
