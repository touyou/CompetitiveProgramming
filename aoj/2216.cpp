#include <cstdio>
#include <cstring>
int res[3];
int main() {
    int a, b;
    while (scanf("%d%d",&a,&b)) {
        if (!a&&!b) break;
        int r=b-a;
        res[2]=r/1000;
        r%=1000;
        res[1]=r/500;
        r%=500;
        res[0]=r/100;
        for (int i=0; i<3; i++) printf("%d%c",res[i],i==2?'\n':' ');
    }
}
