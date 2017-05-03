#include <iostream>
using namespace std;
string b[8];
int main() {
    for (int i=0; i<8; i++) cin>>b[i];
    cout<<90<<endl;
    for (int i=0; i<8; i++) {
        for (int j=7; j>=0; j--) {
            cout<<b[j][i];
        }
        cout<<endl;
    }
    cout<<180<<endl;
    for (int i=7; i>=0; i--) {
        for (int j=7; j>=0; j--) {
            cout<<b[i][j];
        }
        cout<<endl;
    }
    cout<<270<<endl;
    for (int i=7; i>=0; i--) {
        for (int j=0; j<8; j++) {
            cout<<b[j][i];
        }
        cout<<endl;
    }
}
