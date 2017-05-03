#include <cstdio>
#include <cmath>
using namespace std;
bool isprime(int n)
{
    for (int i=3; i*i<=n; i+=2) {
        if (n%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    while (scanf("%d",&n)&&n!=0) {
        int res=0;
        for (int i=3; i<=n/2; i+=2) if (isprime(i)&&isprime(n-i)) res++;
        printf("%d\n",res);
    }
}

