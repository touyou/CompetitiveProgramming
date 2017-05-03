#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#define f first
#define s second
using namespace std;
int main() {
    int n, l;
    scanf("%d%d",&n,&l);
    int ls=-1, res=0;
    pair<int, int> mud[n];
    for (int i=0; i<n; i++) {
        scanf("%d%d",&mud[i].f,&mud[i].s);
    }
    sort(mud, mud+n);
    for (int i=0; i<n; i++) {
        int s=mud[i].f, e=mud[i].s;
        if (e<ls) continue;
        ls=max(ls,s);
        int k=(e-ls)/l+((e-ls)%l!=0);
        ls+=k*l; res+=k;
    }
    printf("%d\n",res);
}
