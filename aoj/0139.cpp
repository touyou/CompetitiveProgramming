#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) {
        string snake; cin >> snake;
        if (snake.length()<2) {
            puts("NA");
            continue;
        }
        if (snake[0]=='>'&&snake[1]=='\'') {
            int cnt=0;
            int j;
            for (j=2;j<snake.length();j++) {
                if (snake[j]=='#') break;
                cnt++;
            }
            int n=0;
            for (j+=1;j<snake.length();j++) {
                if (snake[j]=='~') break;
                n++;
            }
            // printf("%d %d\n",cnt,n);
            if(cnt!=n||j!=snake.length()-1) {
                puts("NA");
            } else {
                puts("A");
            }
        } else if (snake[0]=='>'&&snake[1]=='^') {
            bool flag=true;
            string s="";
            for (int i=2; i<snake.length(); i++) {
                if (snake[i]=='~') break;
                s+=snake[i];
                if (s.length()==2) {
                    if (s!="Q="||s!="~~") flag=false;
                    s="";
                }
            }
            if (flag) puts("B");
            else puts("NA");
        } else {
            puts("NA");
        }
    }
}
