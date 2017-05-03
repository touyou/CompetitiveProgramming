#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string num;
    while (cin>>num) {
        if (num=="#") break;
        int len=num.length();
        if (len<3) puts("0");
        else {
            bool isr=true;
            int pos=(num[0]-'0'+2)%3, res1=0, res2=0;
            for (int i=1; i<len; i++) {
                int next=(num[i]-'0'+2)%3;
                if (pos<next&&isr) {
                    res1++; isr=!isr;
                } else if (pos>next&&!isr) {
                    res1++; isr=!isr;
                }
                pos=next; isr=!isr;
            }
            pos=(num[0]-'0'+2)%3; isr=false;
            for (int i=1; i<len; i++) {
                int next=(num[i]-'0'+2)%3;
                if (pos<next&&isr) {
                    res2++; isr=!isr;
                } else if (pos>next&&!isr) {
                    res2++; isr=!isr;
                }
                pos=next; isr=!isr;
            }
            printf("%d\n",min(res1,res2));
        }
    }
}
