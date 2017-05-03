#include <cstdio>
int main() 
{
    int num,res;
    bool flag=true;
    for (int i=0; i<3; i++) {
        scanf("%d",&num);
        if (flag&&num<=168) {
            flag=false;
            res=num;
        }
    }
    if (flag) printf("NO CRASH\n");
    else printf("CRASH %d\n",res);
}

