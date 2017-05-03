/*
ID: fujiyou1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin >> n;
    string orig[n], resp[n];
    for (int i=0; i<n; i++) fin >> orig[i];
    for (int i=0; i<n; i++) fin >> resp[i];
    fout << a+b << endl;
    return 0;
}
