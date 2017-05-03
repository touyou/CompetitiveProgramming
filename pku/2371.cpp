#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
string emp;
int data[100000];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&data[i]);
    sort(data, data+n);
    cin>>emp;
    scanf("%d",&k);
    for (int i=0; i<k; i++) {
        int s; scanf("%d",&s);
        printf("%d\n",data[s-1]);
    }
}