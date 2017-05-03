#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string dict[50];
vector<string> res;
int main() {
    int n; cin>>n;
    for (int i=0; i<n; i++) cin>>dict[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            res.push_back(dict[i]+dict[j]);
        }
    }
    sort(res.begin(), res.end());
    cout<<res[0]<<endl;
}