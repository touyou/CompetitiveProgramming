#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,mi,b,p,B,P,tmp,tmp2;
    double maxBP;
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        scanf("%d",&n);
        maxBP=0.0;
        P=0;
        for (int i=0; i<n; i++) {
            scanf("%d",&mi);
            tmp=1000000;
            tmp2=1000000;
            for (int j=0; j<mi; j++) {
                scanf("%d %d",&b,&p);
                tmp=min(tmp,b);
                tmp2=min(tmp2,p);
            }
            B=max(B,tmp);
            P+=tmp2;
        }
        maxBP=(double)B/(double)P;
        printf("%.3f\n",maxBP);
    }
}

