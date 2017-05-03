/*
ID: fujiyou1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef long long ll;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    ll c=1,g=1;
    for (int i=0; i<comet.length(); i++) c *= (comet[i]-'A'+1);
    for (int i=0; i<group.length(); i++) g *= (group[i]-'A'+1);
    if (c%47==g%47) fout << "GO" << endl;
    else fout << "STAY" << endl;
    return 0;
}
