/*
ID: fujiyou1
PROG: 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout (".out");
    ifstream fin (".in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}
