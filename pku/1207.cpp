#include <cstdio>

int count(int n)
{
    int cnt=1;
    while (n>1) {
        if (n%2==0) n/=2;
        else n=3*n+1;
        cnt++;
    }
    return cnt;
}

int main()
{
    int i, j;
    while (scanf("%d%d",&i,&j)!=EOF) {
        printf("%d %d",i,j);
        if (i>j) {
            int temp=i;
            i=j;
            j=temp;
        }
        int max=0;
        for (int n=i; n<=j; n++) {
            int temp=count(n);
            if (max<temp) max=temp;
        }
        printf(" %d\n",max);
    }
}
