#include <iostream>
using namespace std;
int main() {
    string set;
    while (cin >> set) {
        if (set == "0") break;
        int a = 0, b = 0;
        for (int i=1; i<set.length(); i++) {
            if (set[i] == 'A') a++;
            if (set[i] == 'B') b++;
        }
        if (a > b) a++;
        else if (a < b) b++;
        cout << a << " " << b << endl;
    }
}
