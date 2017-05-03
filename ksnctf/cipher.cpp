#include <bits/stdc++.h>
using namespace std;
string stc;
int num;
int main() {
    printf("enter the cipher: "); getline(cin, stc);
    printf("enter the key: "); scanf("%d", &num);
    for (int i=0; i<stc.length(); i++) {
        if ('A'<=stc[i]&&stc[i]<='Z') {
            stc[i] = stc[i] - num;
            if ('A' > stc[i]) stc[i] += 26;
            else if ('Z' < stc[i]) stc[i] -= 26;
        } else if ('a'<=stc[i]&&stc[i]<='z') {
            stc[i] = stc[i] - num;
            if ('a' > stc[i]) stc[i] += 26;
            else if ('z' < stc[i]) stc[i] -= 26;
        }
    }
    cout<<stc<<endl;
}
