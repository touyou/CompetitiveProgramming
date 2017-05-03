#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    while (getline(cin, s)) {
        vector<string> part;
        string str="";
        for (int i=0; i<s.length(); i++) {
            if (s[i]==' ') {
                part.push_back(str);
                str="";
            } else {
                str += s[i];
            }
        }
        part.push_back(str);
        string res;
        if (part[0]=="you") res="we";
        else res=part[0];
        for (int i=1; i<part.size(); i++) {
            res += " ";
            if (part[i]=="you") res += "we";
            else res += part[i];
        }
        cout << res << endl;
    }
}
