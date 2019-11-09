#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
string res[8];
/*
 0123456789
0*****     
1     *****
2==========
3 **** ****
4* **** ***
5** **** **
6*** **** *
7**** **** 
*/
int main() {
    int flag=0;
    while (scanf("%d",&n)!=EOF) {
        if (flag) printf("\n");
        else flag=1;
        fill(res, res+8, "");
        res[2]="=====";
        int ten=10000;
        for (int i=0; i<5; i++) {
            int x=n/ten;
            n%=ten;
            ten/=10;
            if (0<=x&&x<=4) {
                res[0]+='*';
                res[1]+=' ';
            } else {
                res[0]+=' ';
                res[1]+='*';
            }
            if (x==0||x==5) res[3]+=' ';
            else res[3]+='*';
            if (x==1||x==6) res[4]+=' ';
            else res[4]+='*';
            if (x==2||x==7) res[5]+=' ';
            else res[5]+='*';
            if (x==3||x==8) res[6]+=' ';
            else res[6]+='*';
            if (x==4||x==9) res[7]+=' ';
            else res[7]+='*';
        }
        for (int i=0; i<8; i++) cout << res[i] << endl;
    }
}
