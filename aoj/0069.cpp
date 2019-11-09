#include <cstdio>
#include <iostream>
using namespace std;
int n, m, g, d;
string ami[30];
int main() {
    while (scanf("%d",&n)) {
        if (!n) break;
        scanf("%d%d%d",&m,&g,&d);
        for (int i=0; i<d; i++) cin>>ami[i];
        
