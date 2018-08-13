#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    char s[128];
    scanf("%d%d%s", &n, &k, s);
    char result[128];
    int diff_cnt = 0;
    int cnt[30] = {0};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    int pos = 0;
    while (pos < n) {
        for (char a='a'; a <= 'z'; a++) {
            if (cnt[a - 'a'] > 0) {
                if (a == s[pos]) {
                    result[pos] = a;
                    pos++;
                    cnt[a - 'a']--;
                    break;
                }
                int rem = k - diff_cnt - 1;
                int tcnt[30] = {0};
                for (int i = pos + 1; i < n; i++) {
                    tcnt[s[i]-'a']++;
                }
                for (char b='a'; b<= 'z'; b++) {
                    if (b == a && tcnt[b - 'a'] > cnt[b - 'a'] - 1) {
                        rem -= (tcnt[b - 'a'] - cnt[b - 'a'] + 1);
                    } if (tcnt[b - 'a'] > cnt[b - 'a']) {
                        rem -= (tcnt[b - 'a'] - cnt[b - 'a']);
                    }
                }
                if (rem < 0) continue;
                else {
                    result[pos] = a;
                    pos++;
                    diff_cnt++;
                    cnt[a - 'a']--;
                    break;
                }
            }
        }
        //printf("%s\n", result);
    }
    printf("%s\n", result);
    return 0;
}
