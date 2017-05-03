#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string in;
    int res=0;
    while (getline(cin,in)) {
        res = max(res, (int)in.length());
    }
    cout << res << endl;
}
