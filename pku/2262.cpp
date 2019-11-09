#include <cstdio>

bool isprime(int n)
{
    if (n == 1) return false;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i < n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n != 0) {
        int res1, res2, diff = 0;
        bool flag = false;
        for (int i = 3; i + i <= n; i += 2) {
            if (!isprime(i)) continue;
            if (isprime(n - i) && !flag) {
                res1 = i;
                res2 = n - i;
                diff = n - i - i;
                flag = true;
            } else if (isprime(n - i) && diff < n - i - i) {
                res1 = i;
                res2 = n - i;
                diff = n - i - i;
            }
        }
        if (flag)
            printf("%d = %d + %d\n", n, res1, res2);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }
}
