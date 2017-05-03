#include <iostream>
#include <string>
using namespace std;
string str, ans;
int main() {
    getline(cin, str);
    for (int i=0; i<str.length(); i+=2) ans.push_back(str[i]);
    cout<<ans<<endl;
}
