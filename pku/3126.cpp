#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;
int itos(string str) {
    int num=0,ten=1000;
    for (int i=0; i<4; i++) {
        num += (str[i]-'0')*ten;
        ten /= 10;
    }
    return num;
}
int main() {
    int isprime[10000];
    fill(isprime, isprime+10000, 1);
    isprime[0]=isprime[1]=0;
    for (int i=2; i<10000; i++) {
        if (isprime[i]) {
            for (int j=i+i; j<10000; j+=i) isprime[j]=0;
        }
    }
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        string num1, num2; cin >> num1 >> num2;
        set<int> res;
        queue<string> que;
        que.push("");
        while (!que.empty()) {
            string str=que.front(); que.pop();
            int len = str.length();
            if (str.length()==4) {
                int x=itos(str);
                printf("%d\n",x);
                if (isprime[x]) res.insert(x);
            } else {
                string str2=str;
                str+=num1[len];
                str2+=num2[len];
                que.push(str);
                que.push(str2);
            }
        }
        printf("%d\n",res.size());
    }
}
