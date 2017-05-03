#include <cstdio>
#include <cstring>
int n;
int num[200][3];
int result[200];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) for (int j=0; j<3; j++) scanf("%d",&num[i][j]);
    memset(result, 0, sizeof(result));
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            int flag=1;
            for (int k=0; k<n&&flag; k++) {
                if (k==i) continue;
                if (num[i][j]==num[k][j]) {
                    flag=0;
                }
            }
            if (flag) result[i]+=num[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d\n",result[i]);
    }
}
