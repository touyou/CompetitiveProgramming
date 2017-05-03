#include <cstdio>
#include <iostream>
using namespace std;
int n;
string a[50];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) cin>>a[i];
    int res=0;
    for (int i=0; i<n; i++) {
        string b; cin>>b;
        if (a[i]==b) res++;
    }
    printf("%d\n",res);
}
