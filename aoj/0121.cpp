#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
const string target="01234567";
struct puzzle {
    string stat;
    int zero;
    puzzle(string _s,int _x) {
        stat=_s;
        zero=_x;
    }
};
int d[4]={-1,1,-4,4};
int n;
int main() {
    queue<puzzle> que;
    map<string, int> done;
    que.push(puzzle(target,0));
    done[target]=0;
    while (!que.empty()) {
        puzzle now = que.front(); que.pop();
        int pos=now.zero;
        for (int i=0; i<4; i++) {
            int nx=pos+d[i];
            if ((nx>=0&&nx<4&&pos>=0&&pos<4)||
                (nx>=4&&nx<8&&pos>=4&&pos<8)||
                (nx>=0&&nx<4&&pos>=4&&pos<8&&abs(nx-pos)==4)||
                (nx>=4&&nx<8&&pos>=0&&pos<4&&abs(nx-pos)==4)) {
                string temp=now.stat;
                swap(temp[pos],temp[nx]);
                if (done.count(temp)==0) {
                    que.push(puzzle(temp,nx));
                    done[temp]=done[now.stat]+1;
                }
            }
        }
    }
    while (scanf("%d",&n)!=EOF) {
        string stats="";
        stats+=(n+'0');
        for (int i=1; i<8; i++) {
            scanf("%d",&n);
            stats+=(n+'0');
        }
        printf("%d\n",done[stats]);
    }
}
