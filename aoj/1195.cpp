// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1195&lang=jp
// プリントの方針通りに
// findを用いて。
#include <bits/stdc++.h>
using namespace std;
vector<string> lists;
string input;
void listsup(char key, string str) {
    if (key == 'a') {
        lists.push_back(str);
        return;
    }
    string::size_type index = str.find(key);
    // cout << key << endl;
    if (index == string::npos) {
        // 使ってない場合
        listsup(key-1, str);
        // 使った場合
        for (int i=0; i<str.length(); i++) {
            if (str[i] == key-1) {
                string temp = str;
                temp[i] = key;
                listsup(key-1, temp);
            }
        }
    } else {
        // それ以前で置き換わっている
        for (int i=0; i<index; i++) {
            if (str[i] == key-1) {
                string temp = str;
                temp[i] = key;
                listsup(key-1, temp);
            }
        }
    }
}
int main() {
    while (cin >> input) {
        if (input == "#") break;
            lists.erase(lists.begin(), lists.end());
            listsup('z', input);
            sort(lists.begin(), lists.end());
            cout << lists.size() << endl;
            if (lists.size() > 10) {
                for (int i=0; i<5; i++) cout << lists[i] << endl;
                for (int i=5; i>0; i--) cout << lists[lists.size()-i] << endl;
            } else {
                for (int i=0; i<lists.size(); i++) cout << lists[i] << endl;
            }
    }
}
