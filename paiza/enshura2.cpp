#include <cstdio>
#include <iostream>
using namespace std;
int n, s, sum[7];
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &s);
        sum[i%7] += s;
    }
    for (int i=0; i<7; i++) cout<<sum[i]<<endl;
}
