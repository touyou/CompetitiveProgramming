#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int res = 0;
    for (int i = a; i <= b; i++) {
        string orig = to_string(i);
        string rev = orig;
        reverse(rev.begin(), rev.end());
        if (orig == rev) res++;
    }
    printf("%d\n", res);
}
