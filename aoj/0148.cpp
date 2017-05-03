#include <cstdio>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n%39==0) printf("3C39\n");
        else if (n%39<10) printf("3C0%d\n",n%39);
        else printf("3C%d\n",n%39);
    }
}

