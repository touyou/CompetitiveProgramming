#include <cstdio>
#include <iostream>
using namespace std;
/*
 * a 0
 * b 1
 * x 2
 * y 3
 * z 4
 * w 5
 * */
int mp[6][2] = {{2,3},{3,2},{-1,4},{2,-1},{5,1},{1,3}};
string str;
int main() {
    while (cin>>str) {
        if (str=="#") break;
        int np = 0;
        for (int i=0; i<str.length(); i++) {
            if (str[i]=='0') np = mp[np][0];
            else if (str[i]=='1') np = mp[np][1];
            if (np==-1) break;
        }
        if (np==1) puts("Yes");
        else puts("No");
    }
}
