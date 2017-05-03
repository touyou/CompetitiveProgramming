#include <cstdio>
int main()
{
    float left,right;
    int lA=0,rA=0,lB=0,rB=0,lC=0,rC=0,lD=0,rD=0;
    while (scanf("%f %f",&left,&right)!=EOF) {
        if (left<0.2) lD++;
        else if (left<0.6) lC++;
        else if (left<1.1) lB++;
        else lA++;
        if (right<0.2) rD++;
        else if (right<0.6) rC++;
        else if (right<1.1) rB++;
        else rA++;
    }
    printf("%d %d\n%d %d\n%d %d\n%d %d\n",lA,rA,lB,rB,lC,rC,lD,rD);
}

