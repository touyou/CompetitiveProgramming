#include <cstdio>
#include <cctype>
#include <iostream>
using namespace std;
int main() 
{
    const char* fact[] = {"379", "397", "739", "793", "937", "973"};    
    int t;
    scanf("%d", &t);
    string in;
    for (int ix=1; ix<=t; ix++) {
        cin >> in;
        string res = "";
        for (int i=0; i<6; i++) {
            int key[in.length()];
            for (int j=0; j<in.length(); j++) key[j] = fact[i][j%3] - '0';
            for (int j=0; j<10; j++) {
                int r = 0;
                for (int k=0; k<in.length(); k++) {
                    if (in[k] == '?') {
                        r += j * key[k];
                    }
                    else if ('0'<=in[k]&&in[k]<='9') {
                        r += (int)(in[k]-'0') * key[k];
                    }
                }
                if (r % 10 == 0) {
                    res = "";
                    for (int k=0; k<in.length(); k++) {
                        if (in[k] == '?') {
                            res += (j + '0');
                        }
                        else if ('0'<=in[k]&&in[k]<='9'){
                            res += in[k];
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        printf("Scenario #%d:\n",ix);
        cout << res << endl;
        cout << endl;
    }
}

// factorsの規則性が不明
