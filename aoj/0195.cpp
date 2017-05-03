#include <cstdio>
#include <algorithm>
using namespace std;
struct map {int n, s; };
bool comp(const map& a, const map& b) {
    return a.s>b.s;
}
map x[5];
int main() {
    int s1, s2;
    while (scanf("%d%d",&s1,&s2)) {
        if (!s1&&!s2) break;
        x[0]=(map){0,s1+s2};
        for (int i=1; i<5; i++) {
            scanf("%d%d",&s1,&s2);
            x[i]=(map){i,s1+s2};
        }
        sort(x,x+5,comp);
        printf("%c %d\n",x[0].n+'A',x[0].s);
    }
}
