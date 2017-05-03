#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct card {
    int num;
    char color;
};
bool comp(const card& a, const card& b) {
    if (a.color!=b.color) return a.color<b.color;
    return a.num<b.num;
}
card tehu[9];
int main() {
    int n; scanf("%d",&n);
    for (int ix=0; ix<n; ix++) {
        for (int i=0; i<9; i++) scanf("%d",&tehu[i].num);
        for (int i=0; i<9; i++) cin>>tehu[i].color;
        sort(tehu, tehu+9, comp);
        char bec='*';
        int ben, cnt=0;
        bool used[9];
        fill(used, used+9, false);
        int sc=0;
        for (int i=0; i<9; i++) {
            if (bec=='*') {
                bec=tehu[i].color;
                ben=tehu[i].num;
                cnt=1;
            } else if (bec!=tehu[i].color) {
                bec=tehu[i].color;
                ben=tehu[i].num;
                cnt=1;
            } else if (ben!=tehu[i].num) {
                ben=tehu[i].num;
                cnt=1;
            } else {
                cnt++;
                if (cnt==3) {
                    used[i]=used[i-1]=used[i-2]=true;
                    cnt=0;
                    bec='*';
                    sc++;
                }
            }
       }
       bec='*';
       for (int i=0; i<9; i++) {
            if (used[i]) continue;
            if (bec=='*') {
                bec=tehu[i].color;
                ben=tehu[i].num;
                cnt=1;
            } else if (bec!=tehu[i].color) {
                bec=tehu[i].color;
                ben=tehu[i].num;
                cnt=1;
            } else if (ben+1!=tehu[i].num) {
                ben=tehu[i].num;
                cnt=1;
            } else {
                ben=tehu[i].num;
                cnt++;
                if (cnt==3) {
                    cnt=0;
                    bec='*';
                    sc++;
                }
            }
       }
       if (sc<3) puts("0");
       else puts("1");
   }
}
