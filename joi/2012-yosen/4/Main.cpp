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

int vx[]={1,0,-1,0},vy[]={0,1,0,-1};

const int MOD=10000;
int dp[100][3][3],bs[100];
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        bs[i]=-1;
    }
    int a,b;
    for(int i=0;i<K;i++){
        scanf("%d%d",&a,&b);
        a--;b--;
        bs[a]=b;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if((bs[0]==i||bs[0]==-1)&&(bs[1]==j||bs[1]==-1)) dp[1][i][j]=1;
            else dp[1][i][j]=0;
        }
    }
    for(int i=2;i<N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k]=0;
                if((bs[i-1]==j||bs[i-1]==-1)&&(bs[i]==k||bs[i]==-1)){
                    for(int l=0;l<3;l++){
                        if(l==j&&j==k) continue;
                        dp[i][j][k]+=dp[i-1][l][j];
                        dp[i][j][k]%=MOD;
                    }
                }
            }
        }
    }
    int ret=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ret+=dp[N-1][i][j];
            ret%=MOD;
        }
    }
    printf("%d\n",ret);
}
