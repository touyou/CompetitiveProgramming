#include <cstdio>
#include <iostream>
using namespace std;
int t, n, po;
string str;
int main() {
    while (scanf("%d%d",&t,&n)) {
        if (!t&&!n) break;
        int sum = 0;
        for (int i=0; i<t; i++) {
            cin>>str>>po;
            sum += po;
        }
        printf("%d\n",3*n-sum);
    }
}
