#include <cstdio>
#include <iostream>
using namespace std;
#define MOD 1000000009
int main() {
    int x; scanf("%d",&x);
    string a="red", b="blue";
    int res1=1,res2=x;
    for (int i=2; i<x; i++) if (x % i==0) {
        res1 = i;
        res2 = x / i;
        break;
    }
    if (res1==1) {
        printf("NO\n");
        return 0;
    }
    printf("%d\n",res1+res2);
    for (int i=0; i<res1; i++) cout << a << endl;
    for (int i=0; i<res2; i++) cout << b << endl;
}
