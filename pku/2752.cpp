#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        vector<int> ans;
        for (int i=1; i<=s.length(); i++) {
            if (s.substr(0,i)==s.substr(s.length()-i,i)) ans.push_back(i);
        }
        for (int i=0; i<ans.size(); i++) {
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
        }
    }
}
