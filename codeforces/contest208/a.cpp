#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string str;
vector<string> ans;
int main() {
    cin>>str;
    string tmp="";
    for (int i=0; i<str.length(); i++) {
        if (str[i]=='W') {
            if (i+1<str.length()&&str[i+1]=='U'&&i+2<str.length()&&str[i+2]=='B') {
                i+=2;
                if (tmp.length()!=0) ans.push_back(tmp);
                tmp="";
            } else {
                tmp+=str[i];
            }
        } else {
            tmp+=str[i];
        }
    }
    if (tmp.length()!=0) ans.push_back(tmp);
    if (ans.size()==0) cout<<endl;
    else {
        cout<<ans[0];
        for (int i=1; i<ans.size(); i++) {
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
}