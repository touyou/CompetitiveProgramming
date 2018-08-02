#include <stdio.h>
#include <ctype.h>
int main() {
    char s[20];
    scanf("%s", s);
    s[0] = toupper(s[0]);
    for (int i = 1; i < 12; i++) {
        if (s[i] == '\n') {
            break;
        }
        s[i] = tolower(s[i]);
    }
    printf("%s\n", s);
    return 0;
}
