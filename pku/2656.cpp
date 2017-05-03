#include <cstdio>
int main() 
{
    int N,school,home;
    while (scanf("%d",&N)&&N!=0) {
        int res=0, time=8;
        for (int i=0; i<N; i++) {
            scanf("%d%d",&school,&home);
            if (school+home>time) {
                time=school+home;
                res=i+1;
            }
        }
        printf("%d\n",res);
    }
}

