#include <cstdio>
int main()
{
    int w;
    while (scanf("%d",&w)&&w!=-1) {
        int res;
        if (w<=10) res=1150;
        else if (w>10&&w<=20) res=1150+(w-10)*125;
        else if (w>20&&w<=30) res=1150+1250+(w-20)*140;
        else res=1150+1250+1400+(w-30)*160;
        printf("%d\n",4280-res);
    }
}

