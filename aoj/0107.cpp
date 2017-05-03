#include <cstdio>
#include <algorithm>
using namespace std;
bool ok(int a, int b, int c) {
    if (a*a+b*b<c*c) return true;
    else return false;
}
int main() 
{
    int row,col,high;
    int n;
    int dir;
    while (scanf("%d%d%d",&row,&col,&high)) {
        if (row==0&&col==0&&high==0) break;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",&dir);
            dir*=2;
            if (ok(row,col,dir)||ok(row,high,dir)||ok(col,high,dir)) {
                printf("OK\n");
            }
            else {
                printf("NA\n");
            }
        }
    }
}

