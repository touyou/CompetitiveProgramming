#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int hh = n / 3600;
    n %= 3600;
    int mm = n / 60;
    n %= 60;
    printf("%02d:%02d:%02d\n", hh, mm, n);
    return 0;
}
