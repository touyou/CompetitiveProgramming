#include <iostream>
using namespace std;
char table[6][5] = {
{'a','b','c','d','e'},
{'f','g','h','i','j'},
{'k','l','m','n','o'},
{'p','q','r','s','t'},
{'u','v','w','x','y'},
{'z','.','?','!',' '}
};
int temp[2];
int main() {
    string mes;
    while (cin>>mes) {
        if (mes.length()%2!=0) cout << "NA" << endl;
        else {
            string res="";
            bool flag=false;
            for (int i=0; i<mes.length(); i++) {
                if (i%2!=0) {
                    temp[1] = mes[i] - '0';
                    if (temp[0]<1||temp[1]<1||temp[0]>6||temp[1]>5) {
                        flag = true;
                        break;
                    } else {
                        res += table[temp[0]-1][temp[1]-1];
                    }
                } else temp[0] = mes[i] - '0';
            }
            if (flag) cout << "NA" << endl;
            else cout << res << endl;
        }
    }
}
