#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, v[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", v + i);
    int odd_cnt[100001] = {0}, max_cnt = 0, second = 0;
    int use_num = -1;
    for (int i = 0; i < n; i += 2) {
        odd_cnt[v[i]]++;
        if (max_cnt < odd_cnt[v[i]]) {
            if (use_num != v[i]) {
                second = max_cnt;
            }
            use_num = v[i];
            max_cnt = odd_cnt[v[i]];
        } else if (second < odd_cnt[v[i]]) {
            second = odd_cnt[v[i]];
        }
    }
    int cnt[100001] = {0}, use_num2 = -1, second2 = 0, max_cnt2 = 0;
    for (int i = 1; i < n; i += 2) {
        cnt[v[i]]++;
        if (max_cnt2 < cnt[v[i]]) {
            if (use_num2 != v[i]) {
                second2 = max_cnt2;
            }
            use_num2 = v[i];
            max_cnt2 = cnt[v[i]];
        } else if (second2 < cnt[v[i]]) {
            second2 = cnt[v[i]];
        }
    }

    if (use_num == use_num2) {
        printf("%d\n", n - max(max_cnt+second2, max_cnt2+second));
    } else {
        printf("%d\n", n - (max_cnt + max_cnt2));
    }
}
