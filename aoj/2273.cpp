#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
string play="aaaaaaaaaa", str;
int main() {
    set<string> used;
    int i=0;
    while (true) {
        bool end=false;
        for (int j=1; j<8; j++) {
            for (int k=0; k<26; k++) {
                play[j]='a'+k;
                if (used.find(play)==used.end()) {
                    cout<<"?"<<play<<endl;
                    fflush(stdout);
                    used.insert(play);
                    cin>>str;
                    if (used.find(str)!=used.end()||str[0]!='a') {
                        end=true;
                        break;
                    }
                    used.insert(str);
                    play[0]=str[str.length()-1];
                }
            }
            if (end) break;
        }
        if (end) {
            puts("!OUT");
            break;
        }
    }
}
