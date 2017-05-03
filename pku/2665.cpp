#include <cstdio>
int main()
{
    int L, M, start, end;
    while (scanf("%d%d", &L, &M)) {
        if (L == 0 && M == 0) break;
        int res = L + 1;
        for (int i=0; i<M; i++) {
            scanf("%d%d", &start, &end);
            res -= end - start + 1;
        }
        printf("%d\n", res);
    }
}

