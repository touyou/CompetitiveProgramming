#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> P;
string field[1000];
int w, h;
int n;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
struct unionfind {
    int par[1000005], rank[1000005];
    unionfind(int w, int h) {
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                par[i*w+j]=i*w+j;
                rank[i*w+j]=i*w+j;
            }
        }
    }
    int find(int x) {
        if (x==par[x]) {
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
};
bool isin(int x, int y) {
    return x>=0&&x<h&&y>=0&&y<w;
}
int main() {
    scanf("%d%d",&w,&h);
    for (int i=0; i<h; i++) cin>>field[i];
    int res=-1;
    unionfind uf(w,h);
    int rx=-1, ry=-1;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (field[i][j]=='t') {
                rx=i; ry=j;
                field[i][j]='.';
            }
            if (field[i][j]=='.') {
                field[i][j]='-';
                queue<P> que;
                que.push(P(i,j));
                while (!que.empty()) {
                    P p=que.front(); que.pop();
                    for (int k=0; k<4; k++) {
                        int nx=p.first+dx[k], ny=p.second+dy[k];
                        if (isin(nx,ny)&&field[nx][ny]=='.') {
                            que.push(P(nx,ny));
                            uf.unite(i*w+j,nx*w+ny);
                            field[nx][ny]='-';
                        } else if (isin(nx,ny)&&field[nx][ny]=='t') {
                            que.push(P(nx,ny));
                            uf.unite(i*w+j,nx*w+ny);
                            rx=nx; ry=ny;
                            field[nx][ny]='-';
                        }
                    }
                }
            }
        }
    }
//    for (int i=0; i<h; i++) cout<<field[i]<<endl;
    int r=rx*w+ry;
    if (uf.same(0,r)) res=0;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        int x, y; scanf("%d%d",&y,&x);
        field[x][y]='-';
        if (res==-1) {
            for (int j=0; j<4; j++) {
                int nx=x+dx[j], ny=y+dy[j];
                if (isin(nx,ny)&&field[nx][ny]=='-') {
                    uf.unite(x*w+y,nx*w+ny);
                }
            }
            if (uf.same(0,r)) res=i;
        }
    }
    printf("%d\n",res);
}
