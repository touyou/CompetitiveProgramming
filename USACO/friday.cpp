/*
ID: fujiyou1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n, now=0;
    int norm[] = {31,28,31,30,31,30,31,31,30,31,30,31}, leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int res[] = {1,0,0,0,0,0,0};
    fin >> n;
    for (int i=1900; i<1900+n; i++) {
        if (i%400==0||(i%100!=0&&i%4==0)) {
            for (int j=0; j<12; j++) {
                now = (now+leap[j]%7)%7;
                if (i!=1900+n-1||j!=11) res[now]++;
            }
        } else {
            for (int j=0; j<12; j++) {
                now = (now+norm[j]%7)%7;
                if (i!=1900+n-1||j!=11) res[now]++;
            }
        }
    }
    for (int i=0; i<6; i++) fout << res[i] << " ";
    fout << res[6] << endl;
    return 0;
}
