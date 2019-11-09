#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    string str;
    while (getline(cin, str)) {
        vector<string> vec;
        stack<double> stc;
        string temp="";
        for (int i=0; i<str.length(); i++) {
            if (str[i]==' ') {
                vec.push_back(temp);
                temp="";
            } else {
                temp+=str[i];
            }
        }
        if (temp.length()!=0) vec.push_back(temp);
        for (int i=0; i<vec.size(); i++) {
            if (vec[i]!="+"&&vec[i]!="-"&&vec[i]!="*"&&vec[i]!="/") {
                stringstream ss;
                ss<<vec[i];
                int n; ss>>n;
                stc.push((double)n);
            } else if (stc.size()>1) {
                double top=stc.top(); stc.pop();
                double top2=stc.top(); stc.pop();
                if (vec[i]=="+") stc.push(top+top2);
                else if (vec[i]=="-") stc.push(top2-top);
                else if (vec[i]=="*") stc.push(top*top2);
                else if (vec[i]=="/") stc.push(top2/top);
            }
        }
        printf("%.6f\n",stc.top());
    }
}
