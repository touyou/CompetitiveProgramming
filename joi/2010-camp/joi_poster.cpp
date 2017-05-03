#include <cstdio>
#include <iostream>
using namespace std;
int len;
int main() {
    int n, k; scanf("%d%d",&n,&k);
    len=1<<n;
    string res="";
    if (k<=len/2) {
        for (int i=0; i<len/2; i++) res+='J';
        for (int i=0; i<len/2; i++) res+='O';
    } else {
        int temp=0;
        int x=n-1;
        temp+=1<<x;
        if ((1<<n)==k) {
            x=0;
        } else {
            while (temp<k) temp+=1<<(--x);
            x++;
        }
        for (int i=0; i<(1<<n)-(1<<x); i++) res+='I';
        x--;
        if (x<0) res+='J';
        else {
            for (int i=0; i<1<<x; i++) res+='J';
            while (res.length()<(1<<n)) {
                res+='O';
            }
        }
    }
    cout<<res<<endl;
}
