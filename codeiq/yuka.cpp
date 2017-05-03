#include <bits/stdc++.h>
using namespace std;
char p;
int ye,m,d,sh,sm,eh,em;
int ans;

int main() {
    while(scanf("%c,%d/%02d/%02d,%02d:%02d,%02d:%02d",&p,&ye,&m,&d,&sh,&sm,&eh,&em)!=EOF) {
        // printf("%c,%d/%02d/%02d,%02d:%02d,%02d:%02d\n",p,ye,m,d,sh,sm,eh,em);
        if (p == 'X') {
            x
        } else {
            for (int i=max(sh, 9); i<min(eh,18); i++) {
                y[d-1][i-9] = 1;
            }
        }
    }
    for (int i=0; i<14; i++) {
        x[i][3] = 1; y[i][3] = 1;
        bool flag = false;
        for (int j=0; j<10; j++) {
            if (!flag&&x[i][j]==0&&y[i][j]==0) {
                flag = true;
                ans++;
            } else if (flag&&(x[i][j]==1||y[i][j]==1)) {
                flag = false;
            }
        }
    }
    printf("%d\n",ans);
}
