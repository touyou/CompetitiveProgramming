#include <iostream>
#include <string>
using namespace std;
int main() {
    string orig; getline(cin,orig);
    for (int i=0; i<10; i++) {
        for (int j=0; j<orig.length(); j++) {
            if (orig[j]=='z') orig[j]='a';
            else if (orig[j]!=' '&&orig[j]!='.') orig[j]++;
        }
    }
    cout<<orig<<endl;
}
