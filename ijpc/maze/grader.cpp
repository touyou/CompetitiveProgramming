#include<cstdio>
#include<cstdlib>
#include"maze.h"

static int mode;
static int S, X[1000050];
static int M[1000][1000];
static int W, H, tY, tX, jY, jX;
static int basex, basey, query_cnt;

void send(int b)
{
    if(mode != 0)
        exit(42);
    if(b != 0 && b != 1)
        exit(42);
    if(S == 1000050)
        exit(42);
    
    X[S++] = b;
}

int query(int dx, int dy)
{
    if(dx < -1000 || dx > 1000) exit(42);
    if(dy < -1000 || dy > 1000) exit(42);
    int qx = basex + dx;
    int qy = basey + dy;
    query_cnt++;
    
    if(qx < 0 || qx >= W) return 1;
    if(qy < 0 || qy >= H) return 1;
    return M[qy][qx];
}

int main()
{
    char tmp[1024];
    
    if(scanf("%d%d%d%d%d%d", &W, &H, &tY, &tX, &jY, &jX) != 6) {
        fprintf(stderr, "read error");
        return 1;
    }
    for(int i=0; i<H; ++i) {
        if(scanf("%s", tmp) != 1) {
            fprintf(stderr, "read error");
            return 1;
        }
        for(int j=0; j<W; ++j)
            M[i][j] = tmp[j] == '#' ? 1 : 0;
    }
    
    basex = tX; basey = tY;
    mode = 0;
    taro(W, H, M);
    
    basex = jX; basey = jY;
    mode = 1;
    int res = jiro(W, H, S, X);
    
    fprintf(stderr, "S = %d\n", S);
    fprintf(stderr, "#query = %d\n", query_cnt);
    printf("%d\n", res);
    
    return 0;
}
