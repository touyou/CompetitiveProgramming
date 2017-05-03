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
    int n;
    scanf("%d",&n);
    int a,b,c,d;
    int sco[100];
    for(int i=0;i<n;i++){
        sco[i]=0;
    }
    for(int i=0;i<n*(n-1)/2;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a--;b--;
        if(c>d) sco[a]+=3;
        else if(d>c) sco[b]+=3;
        else if(c==d){
            sco[a]++;
            sco[b]++;
        }
    }
    for(int i=0;i<n;i++){
        int rank=1;
        for(int j=0;j<n;j++){
            if(sco[j]>sco[i]) rank++;
        }
        printf("%d\n",rank);
    }
}
