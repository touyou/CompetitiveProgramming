#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string str;
    bool newline=true;
    while (getline(cin,str)) {
        int len=str.length();
        bool sharp=false;
        for (int i=0; i<len; i++) {
            if (str[i]!=' ') {
                if (str[i]=='#') sharp=true;
                break;
            }
        }
        if (sharp) {
            if (!newline) cout<<endl;
            cout<<str<<endl;
            newline=true;
        } else {
            for (int i=0; i<len; i++) {
                if (str[i]!=' ') cout<<str[i];
            }
            newline=false;
        }
    }
    if (!newline) cout<<endl;
}
