#include <cstdio>
#include <cmath>
#include <cstring>
int par[1001];
int rank[1001];
void init(int n) {
    for (int i=0; i<n; i++) {
        par[i]=i;
        rank[i]=0;
    }
}
int find(int x) {
    if (par[x]==x) {
        return x;
    } else {
        return par[x]=find(par[x]);
    }
}
void unite(int x, int y) {
    x=find(x);
    y=find(y);
    if (x==y) return;
    if (rank[x]<rank[y]) {
        par[x]=y;
    } else {
        par[y]=x;
        if (rank[x]==rank[y]) rank[x]++;
    }
}
bool same(int x, int y) {
    return find(x)==find(y);
}

struct pos { int x, y; };
pos cpu[1001];
double dist(int i, int j) {
    return sqrt((cpu[i].x-cpu[j].x)*(cpu[i].x-cpu[j].x)+(cpu[i].y-cpu[j].y)*(cpu[i].y-cpu[j].y));
}
int n, d, p, q;
char mode;
int con[1001][1001];
bool red[1001];
int main() {
    scanf("%d%d",&n,&d);
    memset(con, 0, sizeof(con));
    for (int i=0; i<n; i++) {
        red[i]=false;
        scanf("%d%d",&cpu[i].x,&cpu[i].y);
    }
    init(n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (dist(i,j)<=d) {
                con[i][j]=1;
                con[j][i]=1;
            }
        }
    }
    while (scanf("%c",&mode)!=EOF) {
        if (mode=='O') {
            scanf("%d", &p);
            red[p-1]=true;
            for (int i=0; i<n; i++) {
                if (con[p-1][i]&&red[i]) {
                    unite(p-1,i);
//                  printf("connect: %d %d\n",p-1,i);
                }
//              printf("%d root: %d\n",i,find(i));
            }
        } else if (mode=='S') {
            scanf("%d%d",&p,&q);
            if (same(p-1,q-1)&&red[p-1]) {
//              printf("%d root: %d %d root :%d\n",p-1,find(p-1),q-1,find(q-1));
                puts("SUCCESS");
            } else {
                puts("FAIL");
            }
        }
    }
}
