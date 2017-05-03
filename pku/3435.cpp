#include <cstdio>
#include <cstring>
int n, grid[100][100];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n*n; i++) for (int j=0; j<n*n; j++)
        scanf("%d",&grid[i][j]);
    bool cor = true;
    // group check
    int isuse[100];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            memset(isuse, 0, sizeof(isuse));
            for (int k=i*n; k<(i+1)*n; k++) for (int l=j*n; l<(j+1)*n; l++) {
                if (grid[k][l] == 0) continue;
                if (isuse[grid[k][l]-1]==1) cor = false;
                else isuse[grid[k][l]-1] = 1;
            }
        }
    }
    // row & column check
    for (int i=0; i<n*n; i++) {
        // row
        memset(isuse, 0, sizeof(isuse));
        for (int j=0; j<n*n; j++) {
            if (grid[i][j] == 0) continue;
            if (isuse[grid[i][j]-1]==1) cor = false;
            else isuse[grid[i][j]-1] = 1;
        }
        // column
        memset(isuse, 0, sizeof(isuse));
        for (int j=0; j<n*n; j++) {
            if (grid[j][i] == 0) continue;
            if (isuse[grid[j][i]-1]==1) cor = false;
            else isuse[grid[j][i]-1] = 1;
        }
    }
    if (cor) puts("CORRECT");
    else puts("INCORRECT");
}
