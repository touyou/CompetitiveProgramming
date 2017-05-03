#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ALL(A)		(A).begin(),(A).end()
#define DUMP(A)    cout<<#A<<"="<<(A)<< endl
#define SIZE(A)    (int)((A).size())
#define MP  make_pair
using namespace std;
typedef long long ll;

int even_vx[]={1,0,-1,-1,-1,0},even_vy[]={0,-1,-1,0,1,1};
int odd_vx[]={1,1,0,-1,0,1},odd_vy[]={0,-1,-1,0,1,1};

bool isbl[102][102];
bool isvis[102][102];
int W,H;
int kabe[102][102];
int solve(int x,int y){
    isvis[x][y]=true;
    int *vx,*vy;
    if(y%2==0){
        vx=even_vx;
        vy=even_vy;
    }else{
        vx=odd_vx;
        vy=odd_vy;
    }
    int ret=0;
    for(int i=0;i<6;i++){
        int nx=x+vx[i],ny=y+vy[i];
        if(0<=nx&&nx<=W+1&&0<=ny&&ny<=H+1){
            if(isbl[nx][ny]){
                ret++;
                kabe[x][y]++;
            }
            else if(!isvis[nx][ny]) ret+=solve(nx,ny);
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&W,&H);
    for(int i=0;i<=H+1;i++){
        for(int j=0;j<=W+1;j++){
            kabe[i][j]=0;
            isbl[i][j]=false;
            isvis[i][j]=false;
        }
    }
    int now;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d",&now);
            if(now==1) isbl[j+1][i+1]=true;
        }
    }
    int len=0;
    for(int i=0;i<=W+1;i++){
        if(!isvis[i][0]){
            len+=solve(i,0);
        }
        if(!isvis[i][H+1]) len+=solve(i,H+1);
    }
    for(int i=0;i<=H+1;i++){
        if(!isvis[0][i]) len+=solve(0,i);
        if(!isvis[W+1][i]) len+=solve(W+1,i);
    }
    printf("%d\n",len);
}
