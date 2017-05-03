#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    string c;
    int am, pm;
    while (cin >> c) {
        scanf("%d%d",&am,&pm);
        int resp = am + pm;
        int price = am * 200 + pm * 300;
        cout << c;
        printf(" %d %d\n", resp, price);
    }
}
