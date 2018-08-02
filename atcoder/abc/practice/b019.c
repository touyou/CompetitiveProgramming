#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1024];
    scanf("%s", s);
    int cnt = 1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i+1] == s[i]) {
            cnt++;
        } else {
            printf("%c%d", s[i], cnt);
            cnt = 1;
        }
    }
    printf("\n");
    return 0;
}
