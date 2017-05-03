#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-5
typedef long long ll;
int T, N, X;
int s[200];
bool C(double p, int id) {
    double target=s[id]+p*X;
    double sum=p;
    for (int i=0; i<N; i++) {
        if (i==id) continue;
        if (s[i]>target) continue;
        sum+=(target-s[i])/X;
    }
    return sum<=1.0;
}
int main() {
    scanf("%d",&T);
    for (int ix=1; ix<=T; ix++) {
        scanf("%d",&N);
        memset(s,0,sizeof(s));
        for (int i=0; i<N; i++) scanf("%d",&s[i]);
        X=0;
        for (int i=0; i<N; i++) X+=s[i];
        printf("Case #%d: ",ix);
        for (int i=0; i<N; i++) {
            double lb=0.0, ub=1.1;
            for (int j=0; j<1000; j++) {
                double mid=(lb+ub)/2;
                if (C(mid,i)) {
                    lb=mid;
                } else {
                    ub=mid;
                }
            }
            printf("%.6f%c",lb*100,i==N-1?'\n':' ');
        }
    }
}
