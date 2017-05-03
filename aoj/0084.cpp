#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> ans;
int main() {
    string str;
    getline(cin,str);
    string word="";
    for (int i=0; i<str.length(); i++) {
        if (str[i]==' '||str[i]==','||str[i]=='.') {
            if (word.length()>=3&&word.length()<=6) {
                ans.push_back(word);
            }
            word="";
        } else {
            word += str[i];
        }
    }
    if (word.length()>=3&&word.length()<=6) ans.push_back(word);
    for (int i=0; i<ans.size()-1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;
}
