#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    string cows="";
    for (int i=0; i<N; i++) {
        char tmp;
        cin>>tmp;
        cows+=tmp;
    }
    int cnt=0;
    while (!cows.empty()) {
        if (cnt!=0&&cnt%80==0) printf("\n");
        string rev=cows;
        reverse(rev.begin(),rev.end());
        if (cows<=rev) {
            putchar(cows[0]);
            cows.erase(0,1);
        }
        else {
            putchar(rev[0]);
            rev.erase(0,1);
            cows=rev;
        }
        cnt++;
    }
    printf("\n");
}

