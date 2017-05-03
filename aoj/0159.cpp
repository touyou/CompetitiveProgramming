#include <cstdio>
#include <cmath>
int main() 
{
    int i,h,w,n;
    while (scanf("%d",&n)&&n!=0) {
        int res=0;
        double mindiff=1000000.0;
        for (int j=0; j<n; j++) {
            scanf("%d %d %d",&i,&h,&w);
            double diff=22.0-(double)w/(h*h)*10000;
            if (diff<0) diff*=-1;
            if (diff<mindiff) {
                mindiff=diff;
                res=i;
            }
        }
        printf("%d\n",res);
    }
}

            
