#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a,b,c,d,e,f;
int main() {
    while (scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)) {
        if (!a&&!b&&!c&&!d&&!e&&!f) break;
        int s1=0, s2=0;
        f+=e; f+=d;
        s1+=e*11; s2+=d*5;
        switch (c%4) {
            case 0: s1+=0; s2+=0; break;
            case 1: s1+=7; s2+=5; break;
            case 2: s1+=6; s2+=3; break;
            case 3: s1+=5; s2+=1; break;
        }
        f+=(c+3)/4;
        if (s2>=b) {
            s1+=(s2-b)*4;
            b=0;
        } else {
            b-=s2;
        }
        f+=(b+8)/9;
        s1+=(9-b%9)%9*4;
        a-=min(s1,a);
        f+=(a+35)/36;
        printf("%d\n",f);
    }
}
