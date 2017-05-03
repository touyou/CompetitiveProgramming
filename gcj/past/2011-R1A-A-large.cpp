#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    for(int ix=1;ix<=T;ix++){
        long long N,PD,PG;
        scanf("%lld%lld%lld",&N,&PD,&PG);
        bool pos;
        if(PG==0){
            if(PD==0) pos=true;
            else pos=false;
        }else if(PG==100){
            if(PD!=100) pos=false;
            else pos=true;
        }else{
            if((long long)(100/__gcd((long long)100,PD))<=N) pos=true;
            else pos=false;
        }
        if(pos) printf("Case #%d: Possible\n",ix);
        else printf("Case #%d: Broken\n",ix);
    }
}
