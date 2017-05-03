#include <cstdio>
int main() {
    int y; scanf("%d",&y);
    if (y%100==0&&y%400!=0) puts("NO");
    else if (y%4==0) puts("YES");
    else puts("NO");
}