#include <cstdio>
int main() {
    int n, x, y, h, w;
    while (scanf("%d",&n)) {
        if (!n) break;
        int res=0;
        for (int i=0; i<n; i++) {
            scanf("%d%d%d%d",&x,&y,&h,&w);
            int sum=x+y+h;
            if (sum<=60&&w<=2) res+=600;
            else if (sum<=80&&w<=5) res+=800;
            else if (sum<=100&&w<=10) res+=1000;
            else if (sum<=120&&w<=15) res+=1200;
            else if (sum<=140&&w<=20) res+=1400;
            else if (sum<=160&&w<=25) res+=1600;
        }
        printf("%d\n",res);
    }
}
