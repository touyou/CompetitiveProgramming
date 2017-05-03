#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() 
{
    string word;
    while (cin>>word) {
        int len = word.length();
        int flag=0;
        string res="";
        for (int ix=0; ix<len; ix++) {
            if (word[ix]=='B'||word[ix]=='F'||word[ix]=='P'||word[ix]=='V') {
                if (flag==1) {
                    flag=0;
                    continue;
                }
                flag=1;
                res+='1';
            }
            else if (word[ix]=='C'||word[ix]=='G'||word[ix]=='J'||word[ix]=='K'||word[ix]=='Q'||word[ix]=='S'||word[ix]=='X'||word[ix]=='Z') {
                if (flag==2) {
                    flag=0;
                    continue;
                }
                flag=2;
                res+='2';
            }
            else if (word[ix]=='D'||word[ix]=='T') {
                if (flag==3) {
                    flag=0;
                    continue;
                }
                flag=3;
                res+='3';
            }
            else if (word[ix]=='L') {
                if (flag==4) {
                    flag=0;
                    continue;
                }
                flag=4;
                res+='4';
            }
            else if (word[ix]=='M'||word[ix]=='N') {
                if (flag==5) {
                    flag=0;
                    continue;
                }
                flag=5;
                res+='5';
            }
            else if (word[ix]=='R') {
                if (flag==6) {flag=0;continue;}
                flag=6;
                res+='6';
            } else {
                flag=0;
            }
        }
        cout<<res<<endl;
    }
}
