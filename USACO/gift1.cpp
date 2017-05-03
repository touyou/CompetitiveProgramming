/*
ID: fujiyou1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np;
    string in;
    map<string, int> p, d;
    vector<string> name;
    fin >> np;
    for (int i=0; i<np; i++) {
        fin >> in;
        p[in]=0;
        d[in]=0;
        name.push_back(in);
    }
    while (fin >> in) {
        int a, n; fin >> a >> n;
        if (n!=0) {
            d[in] += a/n*n;
            for (int i=0; i<n; i++) {
                fin >> in;
                p[in] += a/n;
            }
        }
    }
    for (int i=0; i<np; i++) fout << name[i] << " " << p[name[i]]-d[name[i]] << endl;
    return 0;
}
