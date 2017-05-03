#include <iostream>
using namespace std;
/*
A 11 B 1 C 1111 D 01 E 110 F 10 G 011
  11   1          11   011   11   110
       1          10         01
       1
*/
int main() {
    string map[8], in;
    while (cin>>in) {
        map[0]=in;
        int h;
        string key[4];
        if (in=="00000000") h=0;
        else {
            key[0]=in;
            h=1;
        }
        for (int i=1; i<8; i++) {
            cin>>map[i];
            if (map[i]!="00000000") key[h++]=map[i];
        }
        if (h==4) cout<<"B"<<endl;
        else if (h==1) cout<<"C"<<endl;
        else if (h==3) {
            bool flag=true;
            for (int i=0; i<8; i++) if (key[1][i]=='1') {
                if (key[0][i]=='1') flag=false;
                break;
            }
            if (flag) cout<<"D"<<endl;
            else cout<<"F"<<endl;
        } else {
            bool flag=true;
            for (int i=0; i<8; i++) if (key[0][i]=='1') {
                if (key[1][i]=='0') flag=false;
                break;
            }
            if (flag) {
                for (int i=0; i<8; i++) if (key[1][i]=='1') {
                    if (key[0][i]=='0') flag=false;
                    break;
                }
                if (flag) cout<<"A"<<endl;
                else cout<<"G"<<endl;
            } else {
                cout<<"E"<<endl;
            }
        }
    }
}
