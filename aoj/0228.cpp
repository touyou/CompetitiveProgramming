#include <cstdio>
#include <iostream>
using namespace std;
string sig[11]={
"0111111",
"0000110",
"1011011",
"1001111",
"1100110",
"1101101",
"1111101",
"0100111",
"1111111",
"1101111"
};
string now;
int main() {
    int n;
    while (scanf("%d",&n)) {
        if (n==-1) break;
        now="0000000";
        for (int i=0; i<n; i++) {
            int s; scanf("%d",&s);
            string res="";
            for (int j=0; j<7; j++) {
                if (now[j]==sig[s][j]) res+='0';
                else res+='1';
            }
            cout<<res<<endl;
            now=sig[s];
        }
    }
}
