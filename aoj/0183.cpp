#include <iostream>
#include <cstdio>
using namespace std;
string f[3];
int main() {
    while (cin>>f[0]) {
        if (f[0]=="0") break;
        for (int i=1; i<3; i++) cin>>f[i];
        char res='+';
        for (int i=0; i<3; i++) {
            if (f[0][i]==f[1][i]&&f[1][i]==f[2][i]) {
                if (f[0][i]!='+') res=f[0][i];
            }
            if (f[i][0]==f[i][1]&&f[i][1]==f[i][2]) {
                if (f[i][0]!='+') res=f[i][0];
            }
        }
        if (f[0][0]==f[1][1]&&f[1][1]==f[2][2]) {
            if (f[0][0]!='+') res=f[0][0];
        }
        if (f[0][2]==f[1][1]&&f[1][1]==f[2][0]) {
            if (f[0][2]!='+') res=f[0][2];
        }
        if (res=='+') puts("NA");
        else cout<<res<<endl;
    }
}
