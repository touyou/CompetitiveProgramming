#include <cstdio>
#include <iostream>
using namespace std;
int t;
string n;
int main() {
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        cin>>n;
        int res=0;
        for (int i=0; i<n.length(); i++) {
            if (n[i]!='4'&&n[i]!='7') res++;
        }
        printf("%d\n",res);
    }
}
