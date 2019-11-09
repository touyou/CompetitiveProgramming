#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
string str;
string sub1(int x) {
    string res="";
    for (int i=0; i<x+1; i++) {
        res+=str[i];
    }
    return res;
}
string sub2(int x) {
    string res="";
    for (int i=x+1; i<str.length(); i++) {
        res+=str[i];
    }
    return res;
}
int main() {
    int m;
    scanf("%d",&m);
    for (int ix=0; ix<m; ix++) {
        cin>>str;
        set<string> res;
        res.insert(str);
        for (int i=0; i<str.length()-1; i++) {
            string h=sub1(i);
            string t=sub2(i);
            string rh=h, rt=t;
            reverse(rh.begin(), rh.end());
            reverse(rt.begin(), rt.end());
//            res.insert(h+t);
            res.insert(t+h);
            res.insert(rh+t);
            res.insert(t+rh);
            res.insert(h+rt);
            res.insert(rt+h);
            res.insert(rh+rt);
            res.insert(rt+rh);
        }
        printf("%d\n",res.size());
    }
}
