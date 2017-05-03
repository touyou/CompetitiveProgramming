#include <cstdio>
#include <cstring>
int n, s, res;
bool used[10];
void dfs(int k, int x) {
    if (x==n+1) {
        if (k==s) res++;
        return;
    }
    for (int i=0; i<10; i++) {
        if (used[i]) continue;
        used[i]=true;
        dfs(k+i*x,x+1);
        used[i]=false;
    }
}
int main() {
    while (scanf("%d%d",&n,&s)!=EOF) {
        memset(used,0,sizeof(used));
        res=0;
        for (int i=0; i<10; i++) {
            used[i]=true;
            dfs(i,2);
            used[i]=false;
        }
        printf("%d\n",res);
    }
}
