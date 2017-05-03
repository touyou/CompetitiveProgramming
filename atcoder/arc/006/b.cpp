#include <cstdio>
#include <iostream>
using namespace std;
int n, l, g;
string amida[20], goal;
int main() {
    scanf("%d%d",&n,&l);
    getline(cin,goal);
    for (int i=0; i<l; i++) {
        getline(cin, amida[i]);
    }
    getline(cin, goal);
    for (int i=0; i<2*n-1; i++) if (goal[i]=='o') g=i;
    for (int i=l-1; i>=0; i--) {
        if (g>=2&&amida[i][g-1]=='-') g-=2;
        else if (g<=2*n-3&&amida[i][g+1]=='-') g+=2;
    }
    printf("%d\n",g/2+1);
}