/*
ID: fujiyou1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#define F first
#define S second
using namespace std;

typedef pair<int, int> P;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n, r1=0, r2=0;
    fin >> n;
    P time[n];
    for (int i=0; i<n; i++) fin >> time[i].F >> time[i].S;
    sort(time, time+n);
    int start=time[0].F, end=time[0].S;
    for (int i=1; i<n; i++) {
        cout << time[i].F << "|" << r1  << "|" << r2 << endl;
        if (end>=time[i].F&&end<time[i].S) {
            end = time[i].S;
        } else if (end<time[i].F) {
            r1 = max(r1, end-start);
            r2 = max(r2, time[i].F-end);
            start = time[i].F;
            end = time[i].S;
        }
    }
    r1 = max(r1, end-start);
    fout << r1 << " " << r2 << endl;
    return 0;
}
