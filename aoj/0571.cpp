#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void init(int *cnt) {
    for (int i=0; i<3; i++) cnt[i]=0;
}
int me(int *cnt) {
    int res=INT_MAX;
    for(int i=0; i<3; i++) res=min(res,cnt[i]);
    return res;
}
bool isok(int *cnt) {
    if (cnt[0]>=cnt[1]&&cnt[1]<=cnt[2]) return true;
    return false;
}
int cnt[3];
int main() {
    string in;
    cin>>in;
    int res=0;
    char flag='*';
    for (int i=0; i<in.length(); i++) {
        if (flag=='*'&&in[i]=='J') {  // J task start
            init(cnt);
            flag='J';
            cnt[0]++;
        } else if (flag=='I'&&in[i]=='J') {
            if (isok(cnt)) res=max(res,me(cnt));
            flag='J';
            init(cnt);
            cnt[0]++;
        } else if (flag=='J'&&in[i]=='J') {
            flag='J';
            cnt[0]++;
        } else if (flag=='O'&&in[i]=='J') { // J task end
            flag='J';
            init(cnt);
            cnt[0]++;
        } else if (flag=='J'&&in[i]=='O') { // O task start
            flag='O';
            cnt[1]++;
        } else if (flag=='O'&&in[i]=='O') {
            flag='O';
            cnt[1]++;
        } else if (flag=='I'&&in[i]=='O') { // O task end
            if (isok(cnt)) res=max(res,me(cnt));
            flag='*';
        } else if (flag=='O'&&in[i]=='I') { // I task start
            flag='I';
            cnt[2]++;
        } else if (flag=='I'&&in[i]=='I') {
            flag='I';
            cnt[2]++;
        } else if (flag=='J'&&in[i]=='I') { // I task end
            flag='*';
        }
        // for (int j=0; j<3; j++) printf("%d%c",cnt[j],j==2?'\n':' ');
   }
   if (flag=='I'&&isok(cnt)) res=max(res,me(cnt));
   printf("%d\n",res);
}
