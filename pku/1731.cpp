#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int main() {
    cin>>s;
    sort(s.begin(), s.end());
    do {
        cout<<s<<endl;
    } while (next_permutation(s.begin(), s.end()));
}