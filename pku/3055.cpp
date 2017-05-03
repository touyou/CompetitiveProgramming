#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        string x, y; cin>>x>>y;
        vector<int> xnum, ynum;
        for (int i=0; i<x.length(); i++) xnum.push_back(x[i]-'0');
        for (int i=0; i<y.length(); i++) ynum.push_back(y[i]-'0');
        sort(xnum.begin(),xnum.end()); sort(ynum.begin(),ynum.end());
        vector<int>::iterator xun=unique(xnum.begin(), xnum.end());
        vector<int>::iterator yun=unique(ynum.begin(), ynum.end());
        xnum.erase(xun, xnum.end());
        ynum.erase(yun, ynum.end());
        int flag=1;
        for (int i=0; i<min(xnum.size(), ynum.size()); i++) {
            
