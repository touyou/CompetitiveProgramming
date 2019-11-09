#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int num, day;
    string str;
    char input[256];
    vector<int> mon;
    map<int, int> res;
    while (getline(cin,str)&&str.length()!=0) {
        string nstr="";
        for (int i=0; i<str.length(); i++) {
            if (str[i]==',') break;
            else nstr+=str[i];
        }
        stringstream ss;
        ss<<nstr;
        ss>>num;
        mon.push_back(num);
    }
    while (scanf("%s", input)!=EOF) {
        sscanf(input, "%d%*c%d", &num, &day);
        int cnt = count(mon.begin(), mon.end(), num);
        if (cnt != 0) {
            if (res.find(num) == res.end()) {
                res.insert(make_pair(num, cnt+1));
            } else {
                res[num]++;
            }
        }
    }
    map<int, int>::iterator itr;
    for (itr = res.begin(); itr != res.end(); itr++) {
        printf("%d %d\n", (*itr).first, (*itr).second);
    }
}
