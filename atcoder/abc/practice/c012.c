#include <stdio.h>
int main() {
    int table[9][9];
    int sum = 0;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
        table[i][j] = (i + 1) * (j + 1);
        sum += table[i][j];
    }
    int n; scanf("%d", &n);
    int target = sum - n;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
        if (table[i][j] == target) {
            printf("%d x %d\n", i+1, j+1);
        }
    }
    return 0;
}
