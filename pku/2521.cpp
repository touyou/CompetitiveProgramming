#include <cstdio>
int main() 
{
    int N,M,P,C;
    while (scanf("%d%d%d%d",&N,&M,&P,&C)) {
        if (N==0&&M==0&&P==0&&C==0) break;
        int Jame=N+C;
        int customer=M+C-P;
        printf("%d\n",Jame-customer);
    }
}

