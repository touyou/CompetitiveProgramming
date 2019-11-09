#include <cstdio>
#include <algorithm>
using namespace std;
bool isprime[100000];
bool isprimes[100000];
int main() {
    int a, b;
    while (scanf("%d%d",&a,&b)) {
        if (a==-1&&b==-1) break;
        int res=0;
        for (int i=0; i*i<b; i++) isprimes[i]=true;
        for (int i=0; i<b-a; i++) isprime[i]=true;
        for (int i=2; i*i<b; i++) {
            if (isprimes[i]) {
                for (int j=2*i; j*j<b; j+=i) isprimes[j]=false;
                for (int j=max(2, (a+i-1)/i)*i; j<b; j+=i) isprime[j-a]=false;
            }
        }
        for (int i=0; i<b-a; i++) if (isprime[i]&&i+a>1) res++;
        bool flag=true;
        for (int i=2; i*i<b; i++) if (b%i==0) flag=false;
        if (flag) res++;
        printf("%d\n",res);
    }
}
