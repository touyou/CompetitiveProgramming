#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream ifs("misc100.txt");
    string str;

    getline(ifs, str);
    string res = "";
    char c;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (c == str[i]) {
            cnt++;
            if (cnt == 3) res += str[i];
        } else {
            c = str[i];
            cnt = 1;
        }
    }
    cout << res << endl;
}
