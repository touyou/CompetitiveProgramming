#include <stdio.h>
#include <string.h>

int main() {
    char X[60];
    scanf("%s", X);
    int len = strlen(X) - 1;
    int pos = 0;
    while (pos < len) {
        if (X[pos] == 'c' && X[pos+1] == 'h') {
            pos += 2;
        } else if (X[pos] == 'o' || X[pos] == 'k' || X[pos] == 'u') {
            pos++;
        } else {
            break;
        }
    }
    if (pos == len) puts("YES");
    else puts("NO");
    return 0;
}
