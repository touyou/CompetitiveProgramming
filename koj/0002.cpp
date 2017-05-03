#include <cstdio>
#include <iostream>
using namespace std;
string str, ans;
bool isthree() {
    int sum=0;
    for (int i=0; i<str.length(); i++) {
        sum+=str[i]-'0';
    }
    if (sum%3==0) return true;
    return false;
}
bool isfive() {
    char c=str[str.length()-1];
    if (c=='5'||c=='0') return true;
    return false;
}
int main() {
    while (cin>>str>>ans) {
        if (str=="0"&&ans=="0") break;
        bool o1=isthree(), o2=isfive();
        if (o1&&o2&&ans=="FizzBuzz") {
            puts("OK");
        } else if (o1&&!o2&&ans=="Fizz") {
            puts("OK");
        } else if (!o1&&o2&&ans=="Buzz") {
            puts("OK");
        } else if (!o1&&!o2&&ans==str) {
            puts("OK");
        } else {
            puts("NG");
        }
    }
}
