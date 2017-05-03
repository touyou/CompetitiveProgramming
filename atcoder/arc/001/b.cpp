#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int a, b; scanf("%d%d",&a,&b);
    if (a>b) swap(a,b);
    int res=0, diff=b-a;
    if (diff%10>=8) {
        res+=(diff+9)/10;
        diff-=(diff+9)/10*10;
    } else {
        res+=diff/10;
        diff-=diff/10*10;
    }
    if (diff%5>=4) {
        res+=(diff+4)/5;
        diff-=(diff+4)/5*5;
    } else {
        res+=diff/5;
        diff-=diff/5*5;
    }
    res+=abs(diff);
    printf("%d\n",res);
}