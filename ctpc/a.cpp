#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);
int x=max(max(a,b),max(c,d));
if ((x+a+b+c+d)/5>=60) puts("Yes");
else puts("No");
}
