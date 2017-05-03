#include <cstdio>
int main() 
{
    long long int A,B,C,f1,f2,f3;
    while(scanf("%lld%lld%lld",&f3,&f2,&f1)!=EOF) {
        C=f3;
        f2-=C; f1-=C;
        A=(f1-f2*2)/2;
        B=f2-A;
        printf("%lld %lld %lld\n",A*9+B*3+C,A*16+B*4+C,A*25+B*5+C);
    }
}

