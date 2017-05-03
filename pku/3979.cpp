#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int gcd(int a,int b)
{
    return b != 0 ? gcd(b, a%b) : a;
}
int main() 
{
    int a,b,c,d;
    char calc;
    while (scanf("%d/%d",&a,&b)!=EOF) {
        cin>>calc;
        scanf("%d/%d",&c,&d);
        int gd=gcd(b,d);
        int res1,res2=b*d/gd;
        a*=res2/b;
        c*=res2/d;
        if (calc=='+') res1=a+c;
        else if (calc=='-') res1=a-c;
        int tmp;
        if (res1<0) tmp=res1*-1;
        else tmp=res1;
        gd=gcd(tmp,res2);
        res1/=gd;
        res2/=gd;
        if (res1==0) printf("0\n");
        else if (res2==1) printf("%d\n",res1);
        else printf("%d/%d\n",res1,res2);
    }
}

