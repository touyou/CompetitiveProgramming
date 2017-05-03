#include <cstdio>

int n;
int play[205][3], cnt[3][105], res[205];

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) for(int j=0; j<3; j++) {
        scanf("%d",&play[i][j]);
        cnt[j][play[i][j]]++;
    }
    for(int i=0; i<n; i++) for(int j=0; j<3; j++) {
        if (cnt[j][play[i][j]]==1) res[i]+=play[i][j];
    }
    for(int i=0; i<n; i++) printf("%d\n", res[i]);
}
