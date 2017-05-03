/*
ID: fujiyou1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n, res=0; string b;
    fin >> n >> b;
    b += b;
    int next=0, now=0;
    char f,s;
    while (now<n) {
        f=b[now];
        int cnt=0;
        if (f=='w') {
            while (b[now]=='w') {
                now++; cnt++;
            }
            f=b[now];
        }
        while (b[now]==f||b[now]=='w') {
            now++; cnt++;
        }
        next=now;
        if (b[next-1]=='w') {
            next--;
            while (b[next]=='w'&&next>=0) next--;
            next++;
        }
        s=b[now];
        while (b[now]==s||b[now]=='w') {
            now++; cnt++;
        }
        //cout << cnt << b[next] << next << endl;
        now=next;
        res=max(res,cnt);
    }
    if (res>n) res=n;
    fout << res << endl;
    return 0;
}
