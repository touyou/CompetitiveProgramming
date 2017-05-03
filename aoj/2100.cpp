#include <cstdio>
#include <cmath>
using namespace std;
int main() 
{
    int t,n,h,oldh;
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        int max=0,min=0;
        scanf("%d",&n);
        scanf("%d",&oldh);
        for (int i=0; i<n-1; i++) {
            scanf("%d",&h);
            int diff=h-oldh;
            oldh=h;
            if (max<diff) max=diff;
            else if (min>diff) min=diff;
        }
        printf("%d %d\n",max,min*-1);
    }
}

