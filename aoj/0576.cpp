#include <cstdio>
#include <algorithm>
using namespace std;

int l,a,b,c,d;
int m;

int calc(int x, int y) {
    return x%y==0?x/y:x/y+1;
}

int main() {
    scanf("%d%d%d%d%d",&l,&a,&b,&c,&d);
    m = max(calc(a,c),calc(b,d));
    printf("%d\n",l-m);
}
