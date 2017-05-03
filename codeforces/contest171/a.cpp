#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
string a, b;
int main() {
    cin>>a>>b;
    reverse(b.begin(), b.end());
    ll rea, reb;
    stringstream sa; sa<<a; sa>>rea;
    stringstream sb; sb<<b; sb>>reb;
    cout<<rea+reb<<endl;
}
