#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        int pole,n;
        scanf("%d%d",&pole,&n);
        int ants[n];
        for (int i=0; i<n; i++) scanf("%d",&ants[i]);
        int MAX=0,MIN=0;
        for (int i=0; i<n; i++) {
            int maxdis=max(pole-ants[i],ants[i]);
            int mindis=min(pole-ants[i],ants[i]);
            if (MAX<maxdis) MAX=maxdis;
            if (MIN<mindis) MIN=mindis;
        }
        printf("%d %d\n",MIN,MAX);
    }
}

