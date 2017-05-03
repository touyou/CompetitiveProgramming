#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cctype>
using namespace std;
int main() {
    vector<string> out;
    string in;
    while (getline(cin,in)) out.push_back(in);
    if (out.size()==1) {
        if (out[0]=="NO") printf("AC\n");
        else if (isdigit(out[0][0])) {
            if (out[0][0]=='0') printf("AE\n");
            else if (out[0].length()<=3) printf("BEF\n");
            else printf("BF\n");
        }
        else {
            bool flag=true;
            for (int i=0; i<out[0].length(); i++) if (out[0][i]>'H') {
                flag=false;
                break;
            }
            if (flag) {
                for (int i=1; i<out[0].length(); i++) {
                    if (out[0][i-1]>=out[0][i]) flag=false;
                }
                if (out[0].length()!=1&&out[0]!="AC"&&out[0]!="AE"&&out[0]!="BEF"&&out[0]!="BF"&&out[0]!="DH") flag = false;
            }
            string rev=out[0];
            reverse(rev.begin(), rev.end());
            if (flag&&out[0]==rev) printf("H\n");
            else if (flag) printf("DH\n");
            else printf("D\n");
        }
    } else {
        if (out[0][0]=='0'&&isspace(out[0][1])) printf("C\n");
        else if (isdigit(out[1][0])) printf("G\n");
        else printf("A\n");
    }
}
