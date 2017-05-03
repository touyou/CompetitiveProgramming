#include <cstdio>
#include <iostream>
using namespace std;
int rtos(string str) {
    int num=0;
    /* I=1 V=5 X=10 L=50 C=100 D=500 M=1000 */
    for (int i=0; i<str.length(); i++) {
        switch (str[i]) {
            case 'I':
                num++;
                break;
            case 'V':
                num+=5;
                if (i&&str[i-1]=='I') num-=2;
                break;
            case 'X':
                num+=10;
                if (i&&str[i-1]=='I') num-=2;
                if (i&&str[i-1]=='V') num-=10;
                break;
            case 'L':
                num+=50;
                if (i&&str[i-1]=='I') num-=2;
                if (i&&str[i-1]=='V') num-=10;
                if (i&&str[i-1]=='X') num-=20;
                break;
            case 'C':
                num+=100;
                if (i&&str[i-1]=='I') num-=2;
                if (i&&str[i-1]=='V') num-=10;
                if (i&&str[i-1]=='X') num-=20;
                if (i&&str[i-1]=='L') num-=100;
                break;
            case 'D':
                num+=500;
                if (i&&str[i-1]=='I') num-=2;
                if (i&&str[i-1]=='V') num-=10;
                if (i&&str[i-1]=='X') num-=20;
                if (i&&str[i-1]=='L') num-=100;
                if (i&&str[i-1]=='C') num-=200;
                break;
            case 'M':
                num+=1000;
                if (i&&str[i-1]=='I') num-=2;
                if (i&&str[i-1]=='V') num-=10;
                if (i&&str[i-1]=='X') num-=20;
                if (i&&str[i-1]=='L') num-=100;
                if (i&&str[i-1]=='C') num-=200;
                if (i&&str[i-1]=='D') num-=1000;
                break;
        }
    }
    return num;
}
int main() {
    string roman;
    while (cin>>roman) {
        printf("%d\n",rtos(roman));
    }
}
