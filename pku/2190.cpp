#include <iostream>
using namespace std;
int main() {
    string isbn; cin >> isbn;
    int pos, sum=0;
    for (int i=0; i<10; i++) {
        if (isbn[i]=='?') pos=10-i;
        else {
            if (isbn[i]=='X') {
                sum += 10*(10-i);
            } else {
                sum += (isbn[i]-'0')*(10-i);
            }
        }
    }
    int ans=-1;
    for (int i=0; i<11; i++) {
        if ((sum+i*pos)%11==0) {
            ans=i;
        }
    }
    if ((pos!=1&&ans==10)||ans==-1) {
        cout << -1 << endl;
    } else if (pos==1&&ans==10) {
       cout << "X" << endl;
    } else {
       cout << ans << endl;
    }
}
