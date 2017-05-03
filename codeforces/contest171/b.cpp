#include <cstdio>
#define MAX_A 18257
int res[MAX_A];
int main() {
    int a; scanf("%d",&a);
    res[0]=1;
    for (int i=1; i<a; i++) {
        res[i]=res[i-1]+i*2*6;
    }
    printf("%d\n",res[a-1]);
}
