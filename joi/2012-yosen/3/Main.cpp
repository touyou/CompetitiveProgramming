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

int main(){
    int N,A,B,C,cs[100];
    scanf("%d%d%d%d",&N,&A,&B,&C);
    for(int i=0;i<N;i++){
        scanf("%d",&cs[i]);
    }
    sort(cs,cs+N,greater<int>());
    int ma,amo=C;
    ma=amo/A;
    for(int i=0;i<N;i++){
        amo+=cs[i];
        ma=max(ma,amo/(A+B*(i+1)));
    }
    printf("%d\n",ma);
}
