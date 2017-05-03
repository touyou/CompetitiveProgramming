#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
string mp[20];
int b=0, w=0;
int main() {
    for (int i=0; i<19; i++) {
        cin>>mp[i];
        for (int j=0; j<19; j++) {
            if (mp[i][j]=='o') b++;
            if (mp[i][j]=='x') w++;
        }
    }
    if (b<w||abs(b-w)>1) puts("NO");
    else {
        int flag = -1;
        for (int i=0; i<19; i++) {
            int cnt = 0, tmp = 0;
            for (int j=0; j<19; j++) {
                if (".ox"[tmp]==