#include <iostream>
#include <vector>
using namespace std;
vector<string> res;
string str;
int main() {
    while (cin>>str) res.push_back(str);
    for (int i=0; i<res.size(); i++) {
        if (i!=0) cout<<",";
        cout<<res[i];
    }
    cout<<endl;
}
