#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char card[10];
    int cnt = N / 5;
    int rest = N % 5;
    int top = cnt % 6;
    if (top == 0) {
        strcpy(card, "123456");
    } else if (top == 1) {
        strcpy(card, "234561");
    } else if (top == 2) {
        strcpy(card, "345612");
    } else if (top == 3) {
        strcpy(card, "456123");
    } else if (top == 4) {
        strcpy(card, "561234");
    } else {
        strcpy(card, "612345");
    }
    for (int i = 0; i < rest; i++) {
        int l = i % 5, r = (i % 5) + 1;
        char tmp = card[l];
        card[l] = card[r];
        card[r] = tmp;
    }
    printf("%s\n", card);
    return 0;
}
