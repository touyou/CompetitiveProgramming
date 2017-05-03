#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string lr[16]={
"AA","BB","XX","YY",
"AB","BA","XY","YX",
"AX","XA","BX","XB",
"AY","YA","BY","YB"};
bool used[1000];
int main() {
    int n; scanf("%d",&n);
    string str; cin>>str;
    int res=10000;
    for (int p=0; p<16; p++) {
        for (int q=0; q<16; q++) {
            if (p==q) continue;
            string x="", y="";
            for (int i=0; i<n; i++){
                if (lr[p][0]!=str[i]) x+=str[i];
                else {
                    if (i+1<n&&lr[p][1]==str[i+1]) { x+='L'; i++; }
                    else x+=str[i];
                }
            }
            int len=x.length();
            for (int i=0; i<len; i++) {
                if (lr[q][0]!=x[i]) y+=x[i];
                else {
                    if (i+1<len&&lr[q][1]==x[i+1]) { y+='R'; i++; }
                    else y+=x[i];
                }
            }
            res=min(res, (int)y.length());
        }
    }
    printf("%d\n",res);
}