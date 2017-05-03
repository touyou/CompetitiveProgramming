#include <cstdio>
int main()
{
    int R, M, Y;
    scanf("%d%d%d", &R, &M, &Y);
    double inter = 1.0 + (double)R / 100;
    double now = (double)M;
    for (int i = 0; i < Y; i++) {
        now *= inter;
    }
    printf("%d\n",(int)now);
}
