#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
vector<string> map;
int N,M;
void dfs(int x, int y) 
{
    map[x][y]='.';
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (x+i>=0&&x+i<N&&y+j>=0&&y+j<M&&map[x+i][j+y]=='W') {
                    dfs(x+i,j+y);
            }
        }
    }
    return ;   
}

int main()
{
    scanf("%d%d",&N,&M);
    for (int i=0; i<N; i++) {
        string tmp;
        cin>>tmp;
        map.push_back(tmp);
    }
    int res=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j]=='W') {
                dfs(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);
}

