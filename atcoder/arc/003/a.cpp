#include <cstdio>
#include <iostream>
using namespace std;
#define eps 1e-9
/* レートいつつくんですか？？？？ */
int main() {
    int n; string r;
    scanf("%d",&n); cin>>r;
    double sum=0;
    for (int i=0; i<n; i++) {
        if (r[i]=='A') sum+=4.0;
        if (r[i]=='B') sum+=3.0;
        if (r[i]=='C') sum+=2.0;
        if (r[i]=='D') sum+=1.0;
    }
    double res=sum/n;
    printf("%.10f\n",res);
}